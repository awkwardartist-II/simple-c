#include <stdio.h>
#include "Source.h"

#define LINE_MAX 128

FILE *Input;

char *ReadLine() {
    char *Line;
    
    Line = malloc(LINE_MAX);
    fgets(Line, LINE_MAX, Input);

    return Line;
}

void CloseSource() {
    if(Input) {
        fclose(Input);
    }
}

int OpenSource(char *Path) {
    Input = fopen(Path, "r");
    if(!Input) {
        return 0;
    }
    return 1;
}