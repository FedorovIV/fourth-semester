#include <stdio.h>
#include "cword.h"

int main()
{
    char s[128];

    scanf("%s", s);

    struct cword word;

    cword_create(&word, s);
    cword_print(&word);
    printf("\n");
    cword_print_size(&word);
    printf("\n");
    cword_remove(&word);
}
