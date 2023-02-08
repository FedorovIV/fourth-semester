#include <stdio.h>
#include <string.h>
#include "for_debug.h"

void print_line()
{
    printf("_________________________________________________\n");
}

void print_massive_of_int(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void print_massive_of_string(char *a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s ", a[i]);
    }

    printf("\n");
}