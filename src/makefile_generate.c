//
// Created by shobhit on 23/3/23.
//

#include <bits/types/FILE.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "makefile_generate.h"
#include "macro.h"
#include "reqfuncs.h"

// This function takes the directory of the project(where makefile is to be created) as argument
// and creates a makefile at the location,
// and then it divides the makefile into 3 parts with the help of comment blocks
// 3 parts are - Macros block, Obj-code generation block, and executable generation block
// max size of directory can be 10,000 characters
void divideMakefileInParts(char proj_fold[10000]) {
    char file_path[10000];
    strcpy(file_path, proj_fold);
    char f_name[10] = "/Makefile";
    strcat(file_path, f_name);
    // printf("%s\n", file_path); // for debugging
    FILE *m_file = fopen(file_path, "w");

    if( !m_file ) {
        fprintf(stderr, "Error: unable to generate Makefile\n");
        exit(0);
    }
    writeMacros(m_file);
    writeObjCode(m_file, proj_fold);
    writeExec(m_file, proj_fold, executableprog);
    //fprintf(m_file, "%s\n\n", "# MACROS block");
    //fprintf(m_file, "%s\n\n", "# OBJECT_CODE generation block");
    //fprintf(m_file, "%s\n\n", "# EXECUTABLE generation block");
    fclose(m_file);
}

void writeMacros(FILE *fileptr) {
    fprintf(fileptr, "%s\n", "# MACROS block");

    if(fileptr != NULL) {
        if(strcmp(compiler, "null") != 0) {
            fprintf(fileptr, "CC=%s\n", compiler);
        }
        if(strcmp(flag1, "null") != 0) {
            fprintf(fileptr, "CFLAGS=%s\n", flag1);
        }
        if(strcmp(flag2, "null") != 0) {
            fprintf(fileptr, "CFLAGS=%s\n", flag2);
        }
    }
    else {
        fprintf(stderr, "Error : unable to write to macro block\n");
    }
    //mandatory line break after the end of the block
    fprintf(fileptr, "\n");
}

void writeObjCode(FILE *fileptr, char proj_fold[]) {
    fprintf(fileptr, "%s\n", "# OBJECT_CODE generation block");

    if(fileptr != NULL) {
        // read through the directory and find files which meets the condition
        // return name of those files
        int x;
        if( (x = retfilefromDir(proj_fold)) >= 0 ) {
            while(x--) {
                char file_name[100];
                strcpy(file_name, fnamefromdir[x]);
                //fprintf(fileptr, "%s\n", file_name);

                fprintf(fileptr, "%s.o: %s\n", fnamefromdirwoext[x], fnamefromdir[x]);
                fprintf(fileptr, "\t$(CC) $(CFLAGS) %s\n",fnamefromdir[x]);
            }
        }
    }
    else {
        fprintf(stderr, "Error : unable to write to OBJECT_CODE generation block\n");
    }
    //mandatory line break after the end of the block
    fprintf(fileptr, "\n");
}

void writeExec(FILE *fileptr, char proj_fold[], char exec_name[]) {
    fprintf(fileptr, "%s\n", "# EXECUTABLE_CODE generation block");

    if(fileptr != NULL) {
        fprintf(fileptr, "%s: ", exec_name);
        int y,x = 0;
        x = retfilefromDir(proj_fold);
        y = x;
        while(y--) {
            fprintf(fileptr, "%s.o ",fnamefromdirwoext[y]);
        }
        fprintf(fileptr, "\n\t$(CC) ");
        while(x--) {
            fprintf(fileptr, "%s.o ", fnamefromdirwoext[x]);
        }
        fprintf(fileptr, "-o %s", exec_name);
    }
    else {
        fprintf(stderr, "Error : unable to write to EXECUTABLE_CODE generation block\n");
    }
    //mandatory line break after the end of the block
    fprintf(fileptr, "\n");
}