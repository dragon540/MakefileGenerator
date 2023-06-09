//
// Created by shobhit on 1/6/23.
//
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <bits/types/FILE.h>

#include "reqfuncs.h"

extern char fnameFromDir[1000][1000] = {"abcd.c", "abcd.c", "abcd.c"};
extern char fnameFromDirWOExt[1000][1000] = {"ab", "ab", "ab"};

extern char temp_header[1000] = "";

extern char headerFromGivenValidFile[1000][1000] = {"\0"};

int retFileFromDir(char src_folder[]) {
    unsigned int fname_idx = 0;
    int flag = 0;
    struct dirent *dir;
    DIR *dp = opendir(src_folder);

    if(dp) {
        while( (dir = readdir(dp)) != NULL) {
            if(dir->d_type == DT_REG) {
                if (fileIsValidC_Cpp(dir->d_name)) {
                    flag++;
                    strcpy(fnameFromDir[fname_idx], dir->d_name);
                    strcpy(fnameFromDirWOExt[fname_idx],
                           retFileFromDirWOExt(fnameFromDirWOExt[fname_idx],
                                               dir->d_name) );
                    fname_idx++;
                }
            }
            else if(dir->d_type == DT_DIR) {
                //continue for now
                //add logic to traverse through inner folders as well using recursion
                continue;
            }
        }
    }
    return flag;
}

// this function determines whether a given file is a valid c or cpp file or not
// modify this function later if support for other languages is to be added
// return 1 if given file is valid
// return 0 if given file is invalid
int fileIsValidC_Cpp(char file_name[]) {
    unsigned int idx = 0;
    while(file_name[idx] != '\0') {
        if(file_name[idx] == '.') {
            if(file_name[idx + 1] == 'c') {
                if(file_name[idx + 2] == '\0')
                    return 1;
                else if(file_name[idx + 2] == 'p' && file_name[idx + 3] == 'p')
                    return 1;
                else
                    return 0;
            }
            else {
                return 0;
            }
        }
        idx++;
    }
    return 0;
}

char* retFileFromDirWOExt(char* file_name_woext_dest, char* file_name) {
    unsigned int idx = 0;
    while(file_name[idx] != '.') {
        file_name_woext_dest[idx] = file_name[idx];
        idx++;
    }
    return file_name_woext_dest;
}

// this function checks if a given substring is present (from the begining  of the string) in the other string
// return 0 if substring is not present
// return length of the substring if substring is present
int patExist(char* search, char* searchIn) {
    unsigned int idx = 0;
    while(searchIn[idx] != '\0') {
        if(search[idx] != searchIn[idx]) {
            return 0;
        }
        else if( (search[idx] == searchIn[idx]) && (search[idx + 1] == '\0') ) {
            return idx;
        }
        idx++;
    }
}

char* retHeader(char* source) {
    unsigned int idx;

    // cleaning temp_header string before modifying it
    for(unsigned int i=0;i<1000;i++) temp_header[i] = '\0';

    idx = patExist("#include \"", source);
    if(idx == 0) {
        idx = patExist("#include\"", source);
    }
    if(idx == 0) return temp_header;
    else {
        idx++;
        unsigned int t_idx = 0;
        while(source[idx + t_idx] != '"') {
            temp_header[t_idx] = source[idx + t_idx];
            t_idx++;
        }
    }
    return temp_header;
}

void readAllHeaderFromFile(char* srcFileName) {
    // cleaning headerFromGivenValidFile array before modifying it
    for(unsigned i=0;i<1000;i++) {
        strcpy(headerFromGivenValidFile[i], "\0");
    }
    FILE* fptr;
    fptr = fopen(srcFileName, "r");
    char line[100];
    unsigned int idx = 0;
    if(fptr != NULL) {
        while( fgets(line, 100, fptr) ) {
            char src_line[1000];

            strcpy(src_line, retHeader(line));
            strcpy(headerFromGivenValidFile[idx], src_line);
            idx++;
        }
    }
    fclose(fptr);
}