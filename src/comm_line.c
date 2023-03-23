//
// Created by shobhit on 23/3/23.
//
#include <string.h>
#include <stdio.h>

#include "comm_line.h"
#include "macro.h"

void commandLineArgReader(int argc, char* argv[]) {
   unsigned int idx;
   if(argc > 1) {
       for(idx = 0; idx < argc; idx++) {
           if( strcmp(argv[idx], "-ccset") == 0 ) {
               if((idx + 1) < argc) {
                   idx++;
                   compiler = argv[idx];
               }
               else {
                   fprintf(stderr, "compiler argument missing\n");
               }
           }
           else if( strcmp(argv[idx], "-f1") == 0 ) {
               if((idx + 1) < argc) {
                   idx++;
                   flag1 = argv[idx];
               }
               else {
                   fprintf(stderr, "flag_1 argument missing\n");
               }
           }
           else if( strcmp(argv[idx], "-f2") == 0 ) {
               if((idx + 1) < argc) {
                   idx++;
                   flag2 = argv[idx];
               }
               else {
                   fprintf(stderr, "flag_2 argument missing\n");
               }
           }
       }
   }
}