#include <stdio.h>
#include <string.h>

#include "Args.h"

FILE *Input;

int main(int argc, char **argv) {
    char *InputPath;

    if(argc < 2) {
        return 0;
    }
    InputPath = argv[1];
    Input = fopen(InputPath,"r");

    if(!Input) {
        printf("Error opening \'%s\'.\n");
        return -1;
    }
    return 0;
}