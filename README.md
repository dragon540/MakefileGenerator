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
   








