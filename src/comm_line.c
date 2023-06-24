//
// Created by shobhit on 23/3/23.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "comm_line.h"
#include "macro.h"

int block_id_flag = 0;

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
           else if( strcmp(argv[idx], "-S") == 0) {
               if( (idx + 1) < argc) {
                   idx++;
                   src_path = argv[idx];
               }
               else {
                   fprintf(stderr, "Error: source code directory for which Makefile has to be generated is missing\n");
               }
           }
           else if(strcmp(argv[idx], "-exec_name") == 0 ) {
               if ((idx + 1) < argc) {
                   idx++;
                   execProgName = argv[idx];
               }
           }
           else if(strcmp(argv[idx], "-block_comment") == 0) {
               if((idx + 1) < argc) {
                   idx++;
                   block_id_flag = atoi(argv[idx]);
                   printf("block_id_flag = %d\n", block_id_flag); // for debugging
               }
           }
       }
   }
}