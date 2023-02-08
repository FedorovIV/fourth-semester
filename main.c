#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include "for_debug.h"

#define NDEBUG

int main(int argc, char *argv[])
{
    
#ifdef DEBUG
    print_line();
    printf("in function \'%s\':\n", __FUNCTION__);
    print_massive_of_string(argv, argc);
    printf("\n");
    print_line();

#endif

    int count;

    while (getopt(argc, argv, "n") > 0)
    {
        count++;
    }

    

}