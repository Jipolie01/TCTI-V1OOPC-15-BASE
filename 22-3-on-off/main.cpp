#include "hwlib.hpp"

void button_pressed(hwlib::pin_in_out & on,hwlib::pin_in_out & off, hwlib::port_out & leds, int ms)
{
    int counter = 0;
    while(1){
        if(! on.get()){
            hwlib::wait_ms(100);
            counter++;
            hwlib::wait_ms(ms);
                leds.set((1 << counter) - 1);
        }
        else if(! off.get()){
            hwlib::wait_ms(100);
            counter--;
            hwlib::wait_ms(ms);
                leds.set((1 << counter) -1);
    }
}

    
}

int main( void )
{
    //kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
    auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
    auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
    auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );
    
    auto leds = hwlib::port_out_from_pins( led0, led1, led2, led3 );
    
    auto on = hwlib::target::pin_in_out( 3, 8 );
    on.direction_set_input();
    auto off = hwlib::target::pin_in_out( 3, 7 );
    off.direction_set_input();
      
    button_pressed(on,off, leds,50);
    
	return 0;
}
