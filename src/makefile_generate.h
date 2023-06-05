//
// Created by shobhit on 23/3/23.
//

#ifndef MAKEFILEGENERATOR_MAKEFILE_GENERATE_H
#define MAKEFILEGENERATOR_MAKEFILE_GENERATE_H

void divideMakefileInParts(char proj_fold[1000]);

void writeMacros(FILE *fp);
void writeObjCode(FILE *fp, char proj_fold[]);
void writeExec(FILE *fileptr, char proj_fold[], char exec_name[]);

void setAllParForMake(FILE* fileptr, char fnamefromdirwoext[][1000], char proj_fold[]);


#endif //MAKEFILEGENERATOR_MAKEFILE_GENERATE_H
