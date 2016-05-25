#ifndef WALL_HPP
#define WALL_HPP

#include "window.hpp"
#include "drawable.hpp"
#include "vector.hpp"
#include "rectangle.hpp"

class wall : public drawable
{
protected:
    bool filled = 0;
    int update_interval;
    int update_count;
    rectangle figure;
public:
    wall(window & w, const vector & start,const vector & end, const vector & bounce);
    void draw() override;
    void update() override;

};

#endif // WALL_HPP
