//
// Created by shobhit on 1/6/23.
//

#ifndef MAKEFILEGENERATOR_REQFUNCS_H
#define MAKEFILEGENERATOR_REQFUNCS_H

#include <dirent.h>

extern char fnamefromdir[1000][1000];

int retfilefromDir(char* src_folder);
int fileisvalidcorcpp(char* file_name);

#endif //MAKEFILEGENERATOR_REQFUNCS_H
