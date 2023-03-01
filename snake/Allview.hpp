#pragma once
#include <stdio.h>

class View
{

public:
    virtual void draw(void) {};

    virtual ~View() {};

    View() {};

};

class TextVi: public View
{

public:
    void draw() {printf("It's Text\n");};
    TextVi() {};
    ~TextVi() {};

};

class GuiVi: public View
{
public:
    void draw() {printf("It's Gui\n");};
    GuiVi() {};
    ~GuiVi() {};
};