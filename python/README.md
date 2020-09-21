README for build-tool lesson for Python

## Info

* This directory will have the Wahoovian matrix solution/demo in it eventually (but not yet).
* Subdirectory *build-python-demo* has a demo program that we'll use with virtenv and pip, along with a locally installed utility function in a separate file, and a externally installed library, numpy for matrix operations.
* Our program uses Python's built-in logging utlity (just so we can show this like we do for C++ and Java).
* There's a *requirements.txt* file we could use with *pip*.

## Some Background:

* A Python virtual environment is a per-project installation of the Python run-time environment, including the interpreter and *pip*, a package manager for Python. This allows you to have a specific custom build environment for each Python project.  (Each could have different versions of Python, different libraries, etc.)

* The utility *pip* finds and downloads a 3rd party library or package from the internet, storing it in the current Python environment. If you run it outside of running a virtual-environment, that package or library will be global, available for all your projects.  It's a best-practice to control this by using it with virtual-environments. 

* Many IDEs integrate virtual environments and *pip* in a nice way.  For example, IntelliJ by defaults creates a virtual environment for each project, and then from the Project settings menu you can search for and add packages.

## How to build and run our demo from the command-line

* From the repo you'll find just 3 files: two .py files and *requirements.txt*. Copy those into a directory you want to build the program if you don't want to "pollute" your working directory.

* The following steps will create a virtual environment, activate it so we can use it, add the NumPy package to that, and build and run the program.  The following shows the commands (for a Bash shell) that do all of this, and we'll explain these below:
```
cd your-folder-with-the-files
virtualenv --python=python3 ./venv
source ./venv/bin/activate
pip install -r requirements.txt
python main.py
...
deactivate
```
* Note: Type *virtualenv* with no arguments first to see if it's installed.  If not, just install it globally by typing:   *pip install virtualenv*

* The call to *virtualenv* installs a complete Python execution environment in a subdirectory *venv* in the current directory.  (It doesn't matter where you put this. It could be in a central location if you wanted one to share on multiple projects.)  The option shown makes sure you're installing Python 3 if your system has both Python 2 and 3 installed.

* The line starting with *source* "activates" your virtual environment. In essence, it changes your PATH variable so that when you type Python commands it executes the ones defined in the virtual environnment, and it sets things so that Python looks for libraries etc in the virtual environment.  If you're using Windows, you'd type something like: *.\\venv1\\Scripts\\activate*

* To install a package with *pip*, you can just type (say) *pip install numpy* (which installs the *numpy* package).  Type *pip help* to see other things you can do with this package manager.

* For sharing projects in Python, we call *pip* to store a list of what packages are currently installed into a file named (by convention) *requirements.txt*, and then when someone wants to re-create that environment, they call *pip* as shown above to read from that file.  The way we generate the *requirements.txt* file is to type: *pip freeze > requirements.txt* to store what *pip* has installed in the current environment.

* Once you've got your packages install, do your Python work as usual. The commands above show us calling Python on our demo program *main.py*.

* Once you're done and want to leave this virtual environment and change your PATH settings back to what they were before, use the *deactivate* command as shown.  You can come back to this virtual environment anytime later with the *activate* command, and your custom Python environment will be there for you to use again.

## About this program

* This Python program uses the very common convention of defining a main() method and using an *if* statement to execute that only if that file is being "run".  This also shows our own "library" and how it's imported and used.  Comments in the code try to explain this.

* Python comes with its own nice logging utility, and it's demo'd here.  I personally don't like the default format for each line, so I demo'd how to make this what I think is better.


## For more info:

* For logging, here's a nice intro: https://docs.python.org/3/howto/logging.html#logging-basic-tutorial

* For using *pip* and *requirements.txt* to save and share a project's environment, see https://help.pythonanywhere.com/pages/RebuildingVirtualenvs/

* There are many many sites that give basic info on numpy and matrix operations. I looked at this one but I'm not sure it's the best (or even good):  https://www.programiz.com/python-programming/matrix
