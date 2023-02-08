#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "cword.h"

static const int MAX_SIZE = 4096; 
static const int ERR_NO_END = -1;

void cword_remove(struct cword *word)
{
    assert(word->arr);
    free(word->arr);
}

int cword_create(struct cword *word, char *s)
{
    assert(word);
    assert(s);

    int count = 0;

    while (s[count] != '\0' && count < MAX_SIZE)
    {
        count++;
    }

    if (count == MAX_SIZE)
    {
        return(ERR_NO_END);
    }

    word->arr = calloc(count + 1, sizeof(char));

    for (int i = 0; i < count; i++)
    {
        word->arr[i] = s[i];
    }

    word->arr[count] = '\0';

    word->size = count;

}

int cword_print(struct cword *word)
{
    assert(word);
    return printf("%s", word->arr);
}

int cword_print_size(struct cword *word)
{
    assert(word);
    return printf("%d", word->size);
}