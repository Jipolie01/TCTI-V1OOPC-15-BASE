#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGLE_HPP

#include "windows.h"
#include "window.hpp"

class filled_rectangle
{
    int l;
    int q;
    int start_x;
    int start_y;
public:
    filled_rectangle(window & w, int l, int q, int start_x, int start_y);
    ~filled_rectangle();

};

#endif // FILLED_RECTANGLE_HPP
