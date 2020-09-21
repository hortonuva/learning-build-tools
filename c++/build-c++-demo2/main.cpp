#include <iostream>
#include "greeter/greeter.hpp"

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <plog/Log.h> // Step1: include the headers
#include "plog/Initializers/RollingFileInitializer.h"

int main(int argc, char* argv[]) {
    using namespace boost::numeric::ublas;

    plog::init(plog::debug, "myapp_log.txt");
    PLOG_INFO << "Program beginning.";

    greeter("Now running our demo program!");

    std::cout << "Testing Boost Matrix example!" << std::endl;
    matrix<double> m (3, 3);
    for (unsigned i = 0; i < m.size1 (); ++ i)
        for (unsigned j = 0; j < m.size2 (); ++ j) {
            m(i, j) = 3 * i + j;
            PLOG_DEBUG << "Indices " << i << " " << j;
        }
    std::cout << m << std::endl;

    greeter("Demo program ends!");
    PLOG_INFO << "Program ending.";

    return 0;
}
