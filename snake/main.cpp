#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "view.hpp"
#include "TextVi.hpp"
#include "GuiVi.hpp"

const int pause_time = 100000;

int main(int argc, char *argv[])
{

    TextVi printer;

    printer.erase_whole_display();

    while (1)
    {
        printer.my_erase_whole_display();
        printer.print_the_bottom_line(3);
        printer.print_the_top_line(3);
        printer.move_curse_top();
        printf("\n");
        usleep(pause_time);
    }

    printer.move_curse_bot();
    
    // printf("%c[30;A", 0x1b);
    // printf("pososi");

    /*
    printf("\033[10;10H");
    printf("\033[0;31m?\033[0m");

    for (int i = -2; i < 5; i++)
    {
        int x = 10 + i; int y = 10;
        printf("\033[%d;%dH", y, x);
        printf("\033[0;31m?\033[0m");
    }

    for (int i = 0; i < 10; i++)
    {
        int x = 10 + i; int y = 10;
        printf("\033[%d;%dH", y, x);
        printf("\033[0;31m!\033[0m");
    }

    printf("\033[H");
    //printf("pososi");
    //printf("\033[31?\033[0");

    */
}
