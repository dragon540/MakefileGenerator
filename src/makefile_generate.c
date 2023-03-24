//
// Created by shobhit on 23/3/23.
//

#include <bits/types/FILE.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "makefile_generate.h"

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
    fprintf(m_file, "%s\n\n", "# MACROS block");
    fprintf(m_file, "%s\n\n", "# OBJECT_CODE generation block");
    fprintf(m_file, "%s\n\n", "# EXECUTABLE generation block");
}