#include "hwlib.hpp"

void print_patterns(hwlib::pin_in_out & led0 ,hwlib::pin_in_out & led1 ,hwlib::pin_in_out & led2 ,hwlib::pin_in_out & led3 ,int pattern[])
{
        for(int i=0; i < 4; i++){
            if(pattern[i] == 1){
                if(i == 0){
                    led0.set( 1 );
                }else if(i == 1){
                    led1.set( 1 );
                }else if(i == 2){
                    led2.set( 1 );
                }else if(i == 3){
                    led3.set( 1 );
                }
            }else if(pattern[i] == 0){                
                if(i == 0){
                    led0.set( 0 );
                }else if(i == 1){
                    led1.set( 0 );
                }else if(i == 2){
                    led2.set( 0 );
                }else if(i == 3){
                    led3.set( 0 );
                }
            }
        }
        hwlib::wait_ms( 300 );
}

void clear_all(hwlib::pin_in_out & led0 ,hwlib::pin_in_out & led1 ,hwlib::pin_in_out & led2 ,hwlib::pin_in_out & led3){
    led0.set( 0 );
    led1.set( 0 );
    led2.set( 0 );
    led3.set( 0 );
}



int main( void )
{
	//kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    int pattern1[] = {1,1,0,0};
    int pattern2[] = {0,1,1,0};
    int pattern3[] = {0,0,1,1};
    
    auto led0 = hwlib::target::pin_in_out(2,23);
    led0.direction_set_output();
    auto led1 = hwlib::target::pin_in_out(2,24);
    led1.direction_set_output();
    auto led2 = hwlib::target::pin_in_out(2,25);
    led2.direction_set_output();
    auto led3 = hwlib::target::pin_in_out(2,26);
    led3.direction_set_output();
    
    
    for(int i=0; i < 10; i++){
        print_patterns(led0,led1,led2,led3,pattern1);
        clear_all(led0,led1,led2,led3);
        print_patterns(led0,led1,led2,led3,pattern2);
        clear_all(led0,led1,led2,led3);
        print_patterns(led0,led1,led2,led3,pattern3);
        clear_all(led0,led1,led2,led3);
        print_patterns(led0,led1,led2,led3,pattern2);
        clear_all(led0,led1,led2,led3);
    }
	return 0;
}
