//
// Created by shobhit on 1/6/23.
//

#ifndef MAKEFILEGENERATOR_REQFUNCS_H
#define MAKEFILEGENERATOR_REQFUNCS_H

#include <dirent.h>
#include <bits/types/FILE.h>

// this array stores names of valid c or cpp files
extern char fnameFromDir[1000][1000];

// this array stores names of valid c or cpp files without extension
extern char fnameFromDirWOExt[1000][1000];

extern char temp_header[1000];

extern char headerFromGivenValidFile[1000][1000];

int retFileFromDir(char* src_folder);
int fileIsValidC_Cpp(char* file_name);
char* retFileFromDirWOExt(char* file_name_woext_dest, char* file_name);

// this function checks if a given substring is present (from the begining  of the string) in the other string
// return 0 if substring is not present
// return length of the substring if substring is present
int patExist(char* search, char* searchIn);

char* retHeader(char* source);

void readAllHeaderFromFile(char* srcFileName);

#endif //MAKEFILEGENERATOR_REQFUNCS_H
