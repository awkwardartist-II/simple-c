#include <stdio.h>
#include "Source.h"

#define LINE_MAX 128

FILE *Input;
char **Lines;

char *ReadLine() {
    char *Line;
    
    Line = malloc(LINE_MAX);
    fgets(Line, LINE_MAX, Input);

    return Line;
}

int GetLineCount() {
    char c;
    int Count;
    int Seek;

    Seek = ftell(Input);
    fseek(Input, 0, SEEK_SET);

    do {
        c = fgetc(Input);
        if(c == '\n') {
            ++Count;
        }
    } while (c != EOF);

    return Count;
}

void LoadSource() {
    int LineNum;

    LineNum = GetLineCount();
    Lines = malloc(sizeof(char*)*LineNum);

    for(int i = 0; i < LineNum; ++i) {
        Lines[i] = ReadLine();
    }
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