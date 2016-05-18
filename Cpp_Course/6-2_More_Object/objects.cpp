#include "objects.hpp"



objects::objects(window & w):
    l (w,0,10,50,60),
    r (w,0,10,50,60),
    c (w,25,35,25)
    {}

objects::~objects()
{
}

void objects::print(){
    l.print();
    c.print();
    r.print();
}

