#pragma once
#include "view.hpp"
#include "GuiVi.hpp"
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

class TextVi : public View
{
private:
    struct winsize WinSZ;

public:
    TextVi(){};

    ~TextVi(){};

    void draw();

    void get_WinSZ(struct winsize *);

    void erase_whole_display(void);

    void move_curse_XY(int x, int y);

    void print_symbol_XY(char c, int x, int y);
    
    void print_the_line(int y);

    void print_the_bottom_line(int distance_from_bot);
    
    void print_the_top_line(int distance_from_top);

    void move_curse_bot(void);

    void move_curse_top(void);

    void my_erase_whole_display(void);

    void erase_string_Y(int y);
};