#include "hwlib.hpp"

int main(void)
{
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    auto tiltsensor = hwlib::target::pin_in_out( 1, 26 );
    tiltsensor.direction_set_input();
    auto led0 = hwlib::target::pin_out( hwlib::target::pins::d25 );
    
    while(1){
    if(tiltsensor.get()){
        hwlib::wait_ms( 400 );
        hwlib::cout 
         << hwlib::left << hwlib::setw( 5 )
         << " Input : 0 \n";
        led0.set(0);
    }else if(! tiltsensor.get()){
        hwlib::wait_ms( 400 );
      hwlib::cout 
         << hwlib::left << hwlib::setw( 5 )
         << " Input : 1 \n";
        led0.set(1);
    }
    
    }
    
    return 0;
}
