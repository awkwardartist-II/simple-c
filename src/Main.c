#include <stdio.h>
#include <string.h>

#include "Args.h"
#include "Source.h"


int main(int argc, char **argv) {
    char *InputPath;

    if(argc < 2) {
        return 0;
    }
    InputPath = argv[1];

    if(!OpenSource(InputPath)) {
        printf("Error opening \'%s\'.\n");
        return -1;
    }

    CloseSource();
    return 0;
}