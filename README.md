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

The original project is build using CMake, for this a CMakeLists.txt file is stored at /MakefileGenerator 
 (/MakefileGenerator/CMakeLists.txt). 

In order to build, ensure that the CMake utility is already installed (CMake 3.24 or higher is required). 
1) Change current directory to */MakefileGenerator* and 
2) then call *cmake /MakefileGenerator/CMakeLists.txt*

For example:

      $ cd /MakefileGenerator
      $ cmake /MakefileGenerator/CMakeLists.txt

## Generating Makefile:

1) Once the building process is done, makefile for other projects can be generated by calling the executable(of MakefileGenerator)
2) It relies on several command line arguments to get addition information

      | Command    | Function                                                                | Mandatory? | 
      |-------------------------------------------------------------------------|------------|------------------------|
      |-ccset     | For setting compiler                                                    | No
      |-S         | For setting source code directory for which makefile is to be generated | Yes
      |-f1        | For setting compile flag number 1                                       | No
      |-f2        | For setting compile flag number 2                                       | No
      |-exec_name | For setting the name for the executable to be produced                  | No
      |-block_comment| To set option of enabling or disabling block identifying comment in makefile (By default it is disabled)| No

### Example :
      $ ./MakefileGenerator -S /home/Programs.... -ccset gcc -f1 Wall -f2 pipe -exec_name program









