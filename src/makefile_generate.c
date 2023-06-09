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

    // this "all" section is outside any of the three blocks
    setAllParForMake(m_file, fnameFromDirWOExt, proj_fold);

    writeObjCode(m_file, proj_fold);
    writeExec(m_file, proj_fold, execProgName);

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
        fprintf(fileptr, "PROGNAME=%s\n", execProgName);
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
        unsigned int x;
        if((x = retFileFromDir(proj_fold)) >= 0 ) {
            while(x--) {
                char file_name[1000];
                // file name
                strcpy(file_name, fnameFromDir[x]); // file name is stored file_name variable

                printf("%s\n", file_name);
                // for debugging
                //fprintf(fileptr, "%s\n", file_name);


                // remove this once the functionality to read each files for local headers is implemented
                fprintf(fileptr, "%s.o: %s", fnameFromDirWOExt[x], fnameFromDir[x]);

                char filenamewithpath[1000];
                strcpy(filenamewithpath, proj_fold);
                strcat(filenamewithpath, "/");
                strcat(filenamewithpath, file_name);

                readAllHeaderFromFile(filenamewithpath);
                for(int u=0;u<1000;u++) {
                    if(strcmp(headerFromGivenValidFile[u], "\0")!=0) {
                        fprintf(fileptr, " %s", headerFromGivenValidFile[u]);
                        //printf("%d\n", u);
                    }
                }
                fprintf(fileptr, "\n");
                fprintf(fileptr, "\t$(CC) $(CFLAGS) -c %s\n", fnameFromDir[x]);
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
        fprintf(fileptr, "$(PROGNAME): ");
        int y,x = 0;
        x = retFileFromDir(proj_fold);
        y = x;
        while(y--) {
            fprintf(fileptr, "%s.o ", fnameFromDirWOExt[y]);
        }
        fprintf(fileptr, "\n\t$(CC) ");
        while(x--) {
            fprintf(fileptr, "%s.o ", fnameFromDirWOExt[x]);
        }
        fprintf(fileptr, "-o $(PROGNAME)");
    }
    else {
        fprintf(stderr, "Error : unable to write to EXECUTABLE_CODE generation block\n");
    }
    //mandatory line break after the end of the block
    fprintf(fileptr, "\n");
}

// this function writes the "all :...." commands in the makefile
// this is necessary in order to ensure that every command in the makefile is executed
// without this command only the first makefile command is executed
void setAllParForMake(FILE* fileptr, char fnamefromdirwoext[][1000], char proj_fold[]) {
    unsigned int numOfObjFile = retFileFromDir(proj_fold);
    if(numOfObjFile) {
        fprintf(fileptr, "all: ");
    }
    while (numOfObjFile--) {
        char objfile[1000];
        strcpy(objfile, fnamefromdirwoext[numOfObjFile]);
        strcat(objfile, ".o ");
        fprintf(fileptr, "%s", objfile);
    }
    fprintf(fileptr, "$(PROGNAME)\n\n");
}