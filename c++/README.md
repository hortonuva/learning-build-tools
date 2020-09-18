# README for build-tool lesson for c++

## Info

* This directory will have the Wahoovian matrix solution/demo in it eventually (but not yet).
* Subdirectory *build-c++-demo* has a demo program that uses CMake, along with a locally installed library, and a externally installed library.
* The CMakeLists.txt file is heavily commented.  This is the configuration file for CMake. The number of commands is actually fairly small if you ignore the comments (and the setup for Boost).

## Some Background:

* Wikipedia article on CMake: https://en.wikipedia.org/wiki/CMake
* CMake is controlled by a specification or configuration file, CMakeLists.txt.  When you run CMake, it creates a Makefile which is a config file for a very common tool called *make*. You then run *make* to do the actual build. Why two steps?  Make is powerful and on many machines, and does a great job.  But, it's config files are hard to write and are not portable. CMake lets you write create a build-configuration at a higher level of abstraction, with fewer commands, and that's more portable from system to system.
* CMake may need to be installed on a user's machine.
* It can be run from the command-line, but pretty much every IDE that supports C++ allows you to run CMake from within the IDE.  (Right now the instructions below only explain the comamnd-line. We need to figure out and document how it works in VS Code.)

## How to build and run our demo from the command-line

* Often by convention, we create a subdirectory named *build* and go into that directory to build and run the code there.  Why? CMake creates a bunch of files, but if we're using version control, we do NOT want these put under version control. So we can use *.gitignore* to make git not manage everything in *build*.
* Steps to build and run:
   1. From the main project directory, *mkdir build*
   2. Create the build directory, *cd build*
   3. Invoke CMake to do its things, which includes creating a Makefile for *make*.  Type *cmake ..*  (Note: the ".." is important -- it tells CMake to look in the parent directory for its configuration file, but do its work in the current directory.)
   4. Now run the Makefile that CMake created for you. Type:  *make*
   5. BTW, if you wanted to see a verbose mode where every command *make* executes is displayed, type:  *make VERBOSE=1*
   6. If *make* succeeds, an executable file should exist in the build-subdirectory with the name you specified in CMakeLists.txt .  If it's called (say) *my\_program*, on a UNIX-based system to run it you'd type: *./my\_program*
   7. You may not ever need to, but to remove all the files Make creates, type:  *make clean*
   8. If you change your C++ code in a way that doesn't require you to update CMakeLists.txt, you don't need to run *cmake ..* again, just *make*.  (But no harm in doing both commands.)
   9. If you make some change in your C++ code that does require a modification to CMakeLists.txt, you should run both commands.
   
## Info about the demo:

* It's silly, just to show concepts.
* It demos how a programmer might create a utility function, and put its .cpp and .hpp file in a subdirectory.  (FYI, an .hpp file is just a convention for naming header files for C++ programs instead of using .h)  This is the *greeter()* function.
* It demos how a programmer might download code for a 3rd party library and install it in the project directory.  This is the logging library *loguru* which is just two files and is installed in the sub-directory with that same name.  FYI, we do the same thing in CMakeLists.txt to achieve this as we did for the programmer's own utility function.
* It demos how a programmer might use a 3rd party library installed somewhere central on their computer, outside the project directory.  Our library in the demo is Boost's matrix libraries.  Boost is a large and popular set of C++ libraries done by Apache.
* The magic is done by CMake's *find_package* command. It looks places where libraries might be.  Where exactly?  I'm not sure!  I couldn't find clear answers in the documentation.  (A little help here?) 
* On my Mac, there was a copy of the .a files for the Boost library already in */usr/local/lib/libboost_\**.  It found them.
* If your machine doesn't have these, we need to figure out how to download Boost and put them in a right place.  We'll have to explain this to the students.
* If you don't have Boost, comment out all references to Boost stuff and you'll see how things work with the logger and the *greeter()* method.

   
## For more info:

* Our demo didn't need many CMake commands.  The tutorials I have found go deep into harder things quickly, and IMHO are tough for those new to this.
* The official tutorial is in the CMake documentation here: https://cmake.org/cmake/help/latest/guide/tutorial/index.html
* This is also a good tutorial: https://cliutils.gitlab.io/modern-cmake/  (Includes installation instructions.)
   
   
