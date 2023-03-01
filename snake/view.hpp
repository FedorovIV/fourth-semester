#pragma once

class View
{

public:

    virtual ~View() {};

    View() {};

    virtual void draw(void) = 0;

};
