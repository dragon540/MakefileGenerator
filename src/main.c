#include <stdio.h>

#include <string.h>

#include "comm_line.h"
#include "macro.h"
#include "makefile_generate.h"

#include "reqfuncs.h" // for debugging

int main(int argc, char* argv[]) {
    for(int i=0;i<1000;i++) {
        strcpy(fnamefromdir[i], "abcd\n");
    }
    commandLineArgReader(argc, argv);

    char path[1000] = "/home/shobhit/Desktop/TestFolder"; // machine dependent code - written here only for easier
                                                          // debugging
    divideMakefileInParts(path);
    printf("compiler is : %s\n", compiler);
    printf("flag1 is : %s\n", flag1);
    printf("flag2 is : %s\n", flag2);

    printf("%s\n", fnamefromdir[18]);
    return 0;
}
