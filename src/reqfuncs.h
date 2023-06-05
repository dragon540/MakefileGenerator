//
// Created by shobhit on 1/6/23.
//

#ifndef MAKEFILEGENERATOR_REQFUNCS_H
#define MAKEFILEGENERATOR_REQFUNCS_H

#include <dirent.h>

// this array stores names of valid c or cpp files
extern char fnameFromDir[1000][1000];

// this array stores names of valid c or cpp files without extension
extern char fnameFromDirWOExt[1000][1000];

int retFileFromDir(char* src_folder);
int fileIsValidC_Cpp(char* file_name);
char* retFileFromDirWOExt(char* file_name_woext_dest, char* file_name);

#endif //MAKEFILEGENERATOR_REQFUNCS_H
