#include "hwlib.hpp"

class pin_in_all : public hwlib::pin_in {
private:
    hwlib::target::pin_in & button0;
    hwlib::target::pin_in & button1;
public:
    pin_in_all( hwlib::target::pin_in & button0,
                hwlib::target::pin_in & button1):
    button0(button0),
    button1(button1)
    {}

    bool get() override{
        return ((!(button0.get())) && (!(button1.get())));}
};

int main(void)
{
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    hwlib::wait_ms(1000);
    hwlib::cout << "Start";
    
    namespace target = hwlib::target;
    
    auto led        =  target::pin_out(target::pins::d3);
	auto button0    =  target::pin_in(target::pins::d8);
	auto button1    =  target::pin_in(target::pins::d9);
	
    led.set(0);
    
	auto AND = pin_in_all(button0, button1);
	while(1){
		led.set(AND.get());
		hwlib::wait_ms( 2 );
	}
}
