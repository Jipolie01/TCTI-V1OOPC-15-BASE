#ifndef PIN_IN_ALL_HPP
#define PIN_IN_ALL_HPP
#include "hwlib.hpp"

class pin_in_all : public hwlib::pin_in_out
{
private:
hwlib::target::pin_in_out & button0;
hwlib::target::pin_in_out & button1;
public:
    pin_in_all( hwlib::target::pin_in_out & button0,
                hwlib::target::pin_in_out & button1;):
    button0(button0), button1(button1)
    {}
    
    bool get() override{
        return ((!(button0.get())) && (!(button0.get())));
    }

};

#endif // PIN_IN_ALL_HPP
