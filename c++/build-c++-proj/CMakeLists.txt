#####################################################
# CMake configuration file for build-tools demo

cmake_minimum_required(VERSION 3.17)

# For CMake, call this project myapp.  (Excutable file will be named "myapp")
project(myapp
        VERSION 1.0
        DESCRIPTION "testing cmake with boost and logging"
        LANGUAGES CXX)


# set the version of C++ to use (CMake will setup proper compiler options)
set(CMAKE_CXX_STANDARD 14)

#####################################################
# What .cpp files and header files are needed?

# myapp is a CMake "target" that depends on two .cpp files
add_executable(myapp main.cpp loguru/loguru.cpp)

# tell the compiler to also look in subdirectory loguru for header files
target_include_directories(myapp PUBLIC ./loguru)


#####################################################
# Boost library (stored externally to this project)
# Note: found some of these settings in online documentation

# First, we need a few settings for Boost (according to online docs)
set( Boost_USE_STATIC_LIBS OFF )
set( Boost_USE_MULTITHREADED ON )
set( Boost_USE_STATIC_RUNTIME OFF )

# Tell CMake to look in various places on your computer to find ver 1.73.0 of Boost
find_package( Boost 1.73.0 COMPONENTS thread fiber context )

# If it's found, CMake defines some variables "Boost_" which we can use
if ( Boost_FOUND )
    # To compile, our .cpp files need to read Boost's header files
    include_directories( ${Boost_INCLUDE_DIRS} )

    # When object files linked to make executable, need to include Boost's library files
    link_libraries( myapp ${Boost_LIBRARIES} )
    
else()
    message( FATAL_ERROR "Required Boost packages not found. Perhaps add -DBOOST_ROOT?" )
endif()
