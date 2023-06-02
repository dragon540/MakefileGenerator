//
// Created by shobhit on 1/6/23.
//
#include <dirent.h>
#include <stdio.h>
#include <string.h>

#include "reqfuncs.h"

extern char fnamefromdir[1000][1000] = {"abcd", "abcd"
                                                "abcd"};

int retfilefromDir(char src_folder[]) {
    unsigned int fname_idx = 0;
    int flag = 0;
    struct dirent *dir;
    DIR *dp = opendir(src_folder);

    if(dp) {
        while( (dir = readdir(dp)) != NULL) {
            if(dir->d_type == DT_REG) {
                if (fileisvalidcorcpp(dir->d_name)) {
                    flag++;
                    strcpy(fnamefromdir[fname_idx], dir->d_name);
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
int fileisvalidcorcpp(char file_name[]) {
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