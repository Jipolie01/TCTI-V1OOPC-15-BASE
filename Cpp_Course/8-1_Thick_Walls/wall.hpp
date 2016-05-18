#ifndef WALL_HPP
#define WALL_HPP

#include "window.hpp"
#include "rectangle.hpp"
#include "drawable.hpp"
#include "filled_rectangle.hpp"

class wall: public rectangle, public filled_rectangle
{
protected:
    bool filled;
    int update_interval;
    int update_count;
    rectangle r;
    filled_rectangle f;
public:
    wall(window & w, const vector & start, const vector & end, int update_interval, bool filled, int update_count);
    ~wall();
    void update() override;
    void draw() override;

};

#endif // WALL_HPP
