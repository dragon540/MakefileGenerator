#include <stdio.h>

#include "comm_line.h"
#include "macro.h"
#include "makefile_generate.h"

#include "reqfuncs.h" // for debugging

int main(int argc, char* argv[]) {
    commandLineArgReader(argc, argv);

    char path[1000] = "/home/shobhit/Desktop/TestFolder2"; // machine dependent code - written here only for easier
                                                          // debugging
    divideMakefileInParts(path);
    printf("compiler is : %s\n", compiler);
    printf("flag1 is : %s\n", flag1);
    printf("flag2 is : %s\n", flag2);
    return 0;
}
