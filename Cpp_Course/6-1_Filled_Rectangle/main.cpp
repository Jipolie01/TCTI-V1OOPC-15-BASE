// This program prints a black rectangle  (still trying to get it green. 
#include <iostream>
#include "window.hpp"
#include "filled_rectangle.hpp"

using namespace std;

int main(int argc, char **argv){
    /*Making class object wich means ::filled_rectangle is run*/
    window w(128,64,2);
    filled_rectangle f(w,60,50,10,10);
}
