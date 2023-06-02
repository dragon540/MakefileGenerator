//
// Created by shobhit on 23/3/23.
//

#ifndef MAKEFILEGENERATOR_MAKEFILE_GENERATE_H
#define MAKEFILEGENERATOR_MAKEFILE_GENERATE_H

void divideMakefileInParts(char proj_fold[1000]);

void writeMacros(FILE *fp);
void writeObjCode(FILE *fp, char proj_fold[]);
void writeExec(FILE *fp);


#endif //MAKEFILEGENERATOR_MAKEFILE_GENERATE_H
