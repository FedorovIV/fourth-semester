#pragma once

#include "view.hpp"
#include "TextVi.hpp"

class GuiVi: public View
{

public:
    void get_WinSZ() {};
    void draw();
    GuiVi() {};
    ~GuiVi() {};
};