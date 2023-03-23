#include <stdio.h>

#include "comm_line.h"
#include "macro.h"

int main(int argc, char* argv[]) {
    commandLineArgReader(argc, argv);

    printf("compiler is : %s\n", compiler);
    printf("flag1 is : %s\n", flag1);
    printf("flag2 is : %s\n", flag2);

    return 0;
}
