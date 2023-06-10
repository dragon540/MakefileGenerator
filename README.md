# MakefileGenerator

Writing and editing Makefiles manually can be a time-consuming and repetitive task. The aim of this project is to create
a program which when given a relevant source code can itself generate a makefile, with sufficient power for user to 
select compilers, flags, etc.

## Aim :
To generate Makefile for any source code directory 

This project is currently being built with CMakeLists, once it reaches a specific level of operational-ity,
a makefile can be generated with the help of this program itself, and in a sense the whole project can be "bootstrapped".

## Outline :
1) For the purpose of this project, a makefile can be divided into three separate parts - 

   1) Macros 
      ``` 
      CC=g++
      CFLAGS= -c -Wall 
      ```

   2) Object-code generation
      ```
      main.o: main.cpp
          $(CC) $(CFLAGS) main.cpp
      factorial.o: factorial.cpp
          $(CC) $(CFLAGS) factorial.cpp
      hello.o: hello.cpp
          $(CC) $(CFLAGS) hello.cpp
      ```
      
   3) Executable generation
      ```
      prog: main.o factorial.o hello.o
          $(CC) main.o factorial.o hello.o -o prog
      ```
## Build :

**NOTE** : As of now, the project folder for which makefile is to be generated is stored at /MakefileGenerator/src/main.c,
specifically in the variable *char path[1000]*, therefore make sure to specify the path of the project for which makefile
is to be generated at the above specified location before building.

The original project is build using CMake, for this a CMakeLists.txt file is stored at /MakefileGenerator 
 (/MakefileGenerator/CMakeLists.txt). 

In order to build, ensure that the CMake utility is already installed (CMake 3.24 or higher is required). 
1) Change current directory to */MakefileGenerator* and 
2) then call *cmake /MakefileGenerator/CMakeLists.txt*

For example:

      cd /MakefileGenerator
      cmake /MakefileGenerator/CMakeLists.txt









