#include <stdio.h>
#include <string.h>

#include "comm_line.h"
#include "macro.h"
#include "makefile_generate.h"

#include "reqfuncs.h" // for debugging

int main(int argc, char* argv[]) {
    commandLineArgReader(argc, argv);

    //char path[1000] = "/home/shobhit/Desktop/Testing"; // machine dependent code - written here only for easier
                                                          // debugging

    if(strcmp(src_path, "null") != 0) {
        divideMakefileInParts(src_path);
        printf("compiler is : %s\n", compiler);
        printf("flag1 is : %s\n", flag1);
        printf("flag2 is : %s\n", flag2);
    }
    else {
        fprintf(stderr, "Error: src directory missing\n");
    }

    return 0;
}
