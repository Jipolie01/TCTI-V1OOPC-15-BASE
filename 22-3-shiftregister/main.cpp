#include "hwlib.hpp"

void button_pressed(hwlib::pin_in_out & on,hwlib::pin_in_out & off, hwlib::port_out & leds, int ms)
{
    int counter = 0;
    while(1){
        if(! on.get()){
            hwlib::wait_ms(40);
            counter++;
            hwlib::wait_ms(ms);
                leds.set((1 << counter) - 1);
        }
        else if(! off.get()){
            hwlib::wait_ms(40);
            counter--;
            hwlib::wait_ms(ms);
                leds.set((1 << counter) -1);
    }
}
}




int main(void)
{
    //kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    namespace target = hwlib::target;
    
    auto led0 = target::pin_out( hwlib::target::pins::d7 );
    auto led1 = target::pin_out( hwlib::target::pins::d6 );
    auto led2 = target::pin_out( hwlib::target::pins::d5 );
    auto led3 = target::pin_out( hwlib::target::pins::d4 );
    
    auto ds =   target::pin_out( target::pins::d8 );
    auto shcp = target::pin_out( target::pins::d9 );
    auto stcp = target::pin_out( target::pins::d10 );
    auto spi =  hwlib::spi_bus_bit_banged_sclk_mosi_miso(
        stcp,
        ds,
        hwlib::pin_in_dummy
    );
    auto hc595 = hwlib::hc595( spi, shcp );

    
    auto leds = hwlib::port_out_from_pins( led0, led1, led2, led3, hc595.p1, hc595.p2, hc595.p3, hc595.p4 );
    
    auto on = hwlib::target::pin_in_out( 3, 8 );
    on.direction_set_input();
    auto off = hwlib::target::pin_in_out( 3, 7 );
    off.direction_set_input();
    

    button_pressed(on,off, leds,50);
    
    return 0;
}
