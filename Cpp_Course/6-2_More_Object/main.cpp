#include <iostream>
#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "objects.hpp"

using namespace std;

int main(int argc, char **argv)
{
	int amount;
    window w(256,128,2);
    objects o(w);
    o.print();
}
