#include "wall.hpp"
#include <iostream>

using namespace std;

wall::wall(window & w,const vector & start,const vector & end, const vector & bounce):
    drawable(w,start,end, bounce),
    figure(w, start,end),
    update_interval(4),
    update_count(0)
{
}


void wall::draw(){
    if(filled == 0){
        figure.draw();
    }else if(filled == 1){
        figure.draw_filled();
    }
}

void wall::update(){
    if(update_count == update_interval){
        update_count = 0;
        if(filled == 1){
            filled = 0;
            draw();
        }else if(filled == 0){
            filled = 1;
            draw();
        }
    }else if(update_count != update_interval){
        update_count++;
    }
}

