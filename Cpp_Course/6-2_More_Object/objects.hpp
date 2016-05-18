#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "window.hpp"

class objects
{
private:
    line l;
    rectangle r;
    circle c;
    
public:
    objects(window & w);
    ~objects();
    void print();

};

#endif // OBJECTS_HPP
