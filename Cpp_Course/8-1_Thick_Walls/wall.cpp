#include "wall.hpp"

wall::wall(window & w, const vector & start, const vector & end, int update_interval, bool filled, int update_count = 0):
    r(w, start, end),
    f(w,start,end),
    update_interval(update_interval),
    filled(filled),
    update_count(update_count)
{}

wall::~wall()
{
}

void wall::draw(){
    if(filled = 1){
        r.draw();
    }else if(filled = 0){

    }
}


void wall::update(){
    if(update_count > update_interval){
        update_count = 0;
    }else{
        update_count++;
    }
}

