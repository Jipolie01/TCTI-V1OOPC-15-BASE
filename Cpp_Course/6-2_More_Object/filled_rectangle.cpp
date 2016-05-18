#include "filled_rectangle.hpp"


filled_rectangle::filled_rectangle(window & w, int l, int q, int start_x, int start_y)
{
    for(int i = 0; i != l; i++){
        for(int k = 0; k != q; k++){
            w.draw(start_x + i,start_y + k);
        }
    }
}

filled_rectangle::~filled_rectangle()
{
}

