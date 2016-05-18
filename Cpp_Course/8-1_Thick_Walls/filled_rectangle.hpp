#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGLE_HPP

#include "windows.h"
#include "window.hpp"
#include "vector.hpp"


class filled_rectangle
{
    int l;
    int q;
    int start_x;
    int start_y;
public:
    filled_rectangle(window & w, const vector & end, const vector &start);
    ~filled_rectangle();
    //void draw();
    

};

#endif // FILLED_RECTANGLE_HPP
