#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <assert.h>
#include "to_give_a_massive_of_char_from_file.h"

static const int kB = 1024;

//Creates massive of char and counts those numbers.
//Works with struct massive_of_char
//In corret way returns adress of struct

struct massive_of_char *to_give_a_massive_of_char_from_file(char *path, struct massive_of_char *text)
{
    assert(text);

    errno = 0;
    int fd; 
    if ((fd = open((const char *) path, O_RDWR)) < 0)
    {
        fprintf(stderr, "in function \'%s\':", __FUNCTION__);
        perror("");
        return NULL;
    }

    struct stat stat_of_file;

    if (fstat(fd, &stat_of_file) < 0)
    {
        fprintf(stderr, "in function \'%s\':", __FUNCTION__);
        perror("");
        return NULL;
    }

    text->size = (int) stat_of_file.st_size + kB;

    text->arr = calloc(text->size, sizeof(char));

    int i = 0;

    errno = 0;

    while ((read(fd, text->arr + i, 1) > 0) && (i+1 < text->size))
    {
        i++;
    }

    if (i == text->size || errno != 0)
    {
        fprintf(stderr, "in function \'%s\': problem with reading", __FUNCTION__);
        return NULL;
    }

    text->arr[i] = '\0';
    text->num_of_char = i;

    return text;
}

int to_remove_massive_of_char(struct massive_of_char *text)
{
    assert(text);
    free(text->arr);
}
