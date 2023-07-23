#include <stdio.h>
#include <string.h>

const char *Options[] = {
    "-o", 0
};
FILE *Input;

int ValidArg(char *Arg) {
    char *o;

    for(int i=0; Options[i]; ++i) {
        o = Options[i];
        if(!strcmp(Arg, o)) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    char *a;

    for(int i=1; i < argc; ++i) {
        a = argv[i]; 
        if(a[0] != '-') {
           Input = fopen(a,"r");
            if(!Input) {
               printf("Error opening \'%s\'.\n",a);
               return -1;
            }
           continue;
        }
        if(!ValidArg(a)) {
            printf("invalid argument \'%s\'.\n",a);
            return -1;
        }
    }
    return 0;
}