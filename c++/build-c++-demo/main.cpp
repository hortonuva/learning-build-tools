#include <iostream>
#include "greeter/greeter.hpp"

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <loguru.hpp>


int main(int argc, char* argv[]) {
    using namespace boost::numeric::ublas;

    greeter("Now running our demo program!");

    loguru::init(argc, argv);
    loguru::add_file("tools-cpp1.log", loguru::Truncate, loguru::Verbosity_MAX);

    LOG_SCOPE_F(INFO, "Program starts.");

    std::cout << "Testing Boost Matrix example!" << std::endl;
    matrix<double> m (3, 3);
    for (unsigned i = 0; i < m.size1 (); ++ i)
        for (unsigned j = 0; j < m.size2 (); ++ j) {
            m(i, j) = 3 * i + j;
            LOG_SCOPE_F(INFO, "Indices %d, %d.", i, j);
        }
    std::cout << m << std::endl;
    LOG_SCOPE_F(INFO, "Program ends.");

    greeter("Demo program ends!");

    return 0;
}
