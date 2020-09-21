#include <iostream>
#include "greeter.hpp"

void greeter (const char* msg) {
    std::cout << "**********************************************" << std::endl;
    std::cout << "** " << msg << " **" << std::endl;
    std::cout << "**********************************************" << std::endl;
}
