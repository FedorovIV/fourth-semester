#include <stdio.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "TextVi.hpp"
#include "assert.h"

void TextVi::draw (){
    printf("It uses Text\n");
};

void TextVi::get_WinSZ(struct winsize *TheWinSZ){
    assert(TheWinSZ);

    ioctl(STDOUT_FILENO, TIOCGWINSZ, TheWinSZ);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &WinSZ);
};
 
void TextVi::erase_whole_display(void){

    printf("\033[2J");
};

void TextVi::move_curse_XY(int x, int y){

    printf("\033[%d;%dH", y, x);
}

void TextVi::print_symbol_XY(char c, int x, int y){

    move_curse_XY(x, y);
    printf("%c", c);
};

void TextVi::print_the_line(int y){

    struct winsize ws;

    get_WinSZ(&ws);

    int width = ws.ws_col;

    for (int i = 1 ; i <= width; i++)
    {
        int x = i;
        print_symbol_XY('-', x, y);
    }
};

void TextVi::print_the_bottom_line(int distance_from_bot){

    struct winsize ws;

    get_WinSZ(&ws);

    int height = ws.ws_row;

    int y = height - distance_from_bot;

    print_the_line(y);
};


void TextVi::print_the_top_line(int distance_from_top){

    struct winsize ws;

    get_WinSZ(&ws);


    int y = 1 + distance_from_top;

    print_the_line(y);
};

void TextVi::move_curse_bot(void){
    struct winsize ws;

    get_WinSZ(&ws);

    int height = ws.ws_row;

    move_curse_XY(0, height);
};

void TextVi::move_curse_top(void){

    move_curse_XY(0, 1);

};

void TextVi::erase_string_Y(int y){

    move_curse_XY(0, y);
    printf("\033[2K");

}


void TextVi::my_erase_whole_display(void){
    struct winsize ws;

    get_WinSZ(&ws);

    int height = ws.ws_row;

    for (int i = 1; i <= height; i++)
    {
        erase_string_Y(i);
    }
}
