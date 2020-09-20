# README for build-tool lesson for Java

## Info

* This directory will have the Wahoovian matrix solution/demo in it eventually (but not yet).
* Subdirectory *build-hava-demo* has a demo program that uses Gradel, along with a locally installed library, and a externally installed library.
* The build.grade file is heavily commented.  This is the configuration file for Gradle. 

## Some Background:

* A good doc to get started on how to use Gradle to setup, build and run a Java application is here: https://guides.gradle.org/building-java-applications/

* Adapted in part from https://en.wikipedia.org/wiki/Gradle
Gradle is a build automation tool that is popular for Java and Android development, but supports other languages as well. It controls the development process in the tasks of compilation and packaging to testing, deployment, and publishing. It builds on the concepts of Apache Ant and Apache Maven.  Like Maven, it can download dependencies (3rd party libraries) from servers on the internet and make them easy to include in a project's build. 

## How to build and run our demo from the command-line

* You might want to open the "Guides" doc from guides.gradle.org listed above as you do this.

* These instructions explain how the demo provided here was created and built. You might want to repeat these steps in a separate folder, copying from the demo code into your new files, in order to see how this works.

* Create and go to a new empty directory, which I'll call *demo-build* in these instructions.

* When you run Gradle, you give it a task name to do.  To create a new project, type: *gradle init*.  The init task steps you through a menu of choices, described in "Guides" doc. Choose "Java Application", and after that you can accept most of the default choices by hitting "return".  But, to avoid confusion, name the "source package" to be "mypkg" (not demo) just so we are all clear that's a package and not a directory or project name.

* Gradle sets up directory for your project files which is reasonable and should be accepted by beginners. The Guides doc has a nice image of this.  Note that your .java files will be in src/main/java and your test files will be in src/test/java.

* The config file for a build is the file *build.gradle* and we'll work with that a lot.

* Gradle downloads a "wrapper" version of itself into the project folder, with the idea that the version of build program used should be stored with the project to keep things working long-time.  So after running Gradle with *gradle* for init, afterwards we normally invoke Gradle with *gradlew*.  It's OK if you don't do this for demos and coursework.

* The *init* task you ran creates a kind of "hello world" program.  You can build it by typing  *gradlew build* and then run it by typing *gradlew run*.

* If you're curious, all the files from the build operation go into the *build* subdirectory, including all the .class files and a .jar file in *build/libs*.

## Modify the Gradle-created initial code to make it do what our completed demo does

* Our goal is to find and use some 3rd party libraries, and to create a Zip file that can be distributed and run stand-alone because it contains all the classes for those libraries.  (Sure it's big, but your user won't have to add Jar files to CLASSPATH.)

* These instructions are written as if you're looking at the demo code supplied, while update your own project in your own *demo-build* folder.

* Looking in file *build.gradle* file supplied with our demo, you'll see it includes two *plugins*.  No need to change these.

* The *repositories* section names a on-line Gradle repository that stores 3rd party packages.  The one created by *init* listed here (jcenter) is fine.

* The *application* section specifies which Java class has the main() method that you want to execute when your application is run.

* The *jar* section controls creation of the .jar file that will be put in *build/libs* (and can be run from the command-line with the command *java -jar*).  Some of what's here is like a Hogwarts spell you might memorize without knowing exactly why it works.  The *manifest* subsection has to define the class that has main().  The "Multi-Release" setting has to be there to make many 3rd party libraries happy. (Thanks StackOverflow!)  If you want the Jar file to have a different name or append a version number to the Jar file's name, the two lines that are commented out can do that.

* In the *jar* section the code starting with "from" and with the "zipTree" function call are the magic that copies all the 3rd party libraries into your Jar file, and not just your code.  Don't change this if you want your Jar file to be like that.

* We've saved the best for last perhaps:  the *dependencies* section.  This section is what finds and retrieves and includes your 3rd party libraries.  When you find the documentation for a 3rd party library on the Web, many have the lines required for *build.gradle* documented, and you just cut-and-paste them into this file!

* The Gradle *init* task added two here that you can keep or comment out.  One is for JUnit testing, so we might keep that for when we use JUnit.  The other is for a nice Google general purpose data structures library, Guava: https://guava.dev/   BTW, you can specify a dependency in *build.gradle* in two forms, and both of these are in "Maven" format.

* Our demo code uses Apache's popular logging library, "Log4J 2".  It needs two lines to go into *build.gradle*, which I copied from https://logging.apache.org/log4j/2.x/maven-artifacts.html

* Our demo code uses matrix classes from Apache's Common Maths library. https://commons.apache.org/proper/commons-math/userguide/linear.html   It just needs one line in *build.gradle*

* There's a way to specify "the latest version" for a library, but often we want to pick a version and stick with it over a project's lifetime.  (Unless we deliberately change and test our project with the new version.)

* When you execute *gradlew build* after adding these lines, the library is downloaded and stored in a central cache for your account on your machine. The cached version is reused for later builds, but they expire after a fixed period and will be downloaded again if needed. (Where's the cache?  On \*nix machines like a Mac, look in *~/.gradle*.)  But all this is totally handled by Gradle, and you have to do nothing.

* You can run your application with *gradlew run*, and if you made a "fat" Jar file, by typing *java -jar* with the name of the .jar file in *buiid/libs*.


## For more info:


