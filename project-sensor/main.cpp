#include "hwlib.hpp"


void receiver(hwlib::pin_in_out & receiver_pin, hwlib::pin_out & led){
    hwlib::wait_ms(50);
    int output_led = receiver_pin.get();
    hwlib::cout << "Receiving:" << output_led <<"\n" << "Receiving pin.get()" << receiver_pin.get()<<"\n";
    hwlib::wait_ms(1000);
    led.set(output_led);
    hwlib::cout << "Led set:" << "\n" << output_led << "\n";
    hwlib::wait_ms(50);
}

void send(hwlib::pin_in_out & send_pin){
    int input = 1;
    hwlib::wait_ms(400);
    hwlib::cout << "Sending .. \n";
    send_pin.set(input);
    hwlib::cout << "Setting led: "<< input<< "\n";
    hwlib::wait_ms(100);
    
}

void reset(hwlib::pin_in_out & receiver_pin, hwlib::pin_out & led, hwlib::pin_in_out & send_pin){
    send_pin.set(0);
    led.set(0);
    receiver_pin.set(0);
}

int main(void)
{
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    hwlib::wait_ms(1000);
    hwlib::cout << "Test: \n";
    
    auto receiver_pin = hwlib::target::pin_in_out( 1, 27 );
    receiver_pin.direction_set_input();
    auto send_pin = hwlib::target::pin_in_out( 0, 16 );
    send_pin.direction_set_output();
    auto led0 = hwlib::target::pin_out( hwlib::target::pins::d8 );
    
    
    for(int i = 0; i < 10; i++){
    send(send_pin);
    receiver(receiver_pin, led0);
    hwlib::wait_ms(150);
    reset(send_pin,led0,receiver_pin);
    }    
    return 0;
}
