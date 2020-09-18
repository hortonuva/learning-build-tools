# README for build-tool lesson for c++

## Info

* This directory will have the Wahoovian matrix solution/demo in it eventually (but not yet).
* Subdirectory *build-c++-demo* has a demo program that uses CMake, along with a locally installed library, and a externally installed library.
* The CMakeLists.txt file is heavily commented.

## How to build and run this from the command-line

* Often by convention, we create a subdirectory named *build* and go into that directory to build and run the code there.  Why? CMake creates a bunch of files, but if we're using version control, we do NOT want these put under version control. So we can use *.gitignore* to make git not manage everything in *build*.
* Steps to build and run:
   1. From the main project directory, *mkdir build*
   2. Create the build directory, *cd build*
   3. Invoke CMake to do its things, which includes creating a Makefile for *make*.  Type *cmake ..*  (Note: the ".." is important -- it tells CMake to look in the parent directory for its configuration file, but do its work in the current directory.)
   4. Now run the Makefile that CMake created for you:  *make*
   5. If you want to see a verbose mode where every command *make* executes is displayed, type:  *make VERBOSE=1*
   6. If *make* succeeds, whatever you named your executable will be in the build-subdirectory.  If it's called (say) *my\_program*, on a UNIX-based system you'd type: *./my\_program*
* The end!
