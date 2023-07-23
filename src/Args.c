
const char *Options[] = {
    "output", 0
};

const char ShortOpt[] = {
    'o', 0
};

int ArgShort(char *Arg) {
    int Len;

    Len = strlen(Arg);
    if(Len == 2 && *Arg == '-') {
        return 1;
    }
    return 0;
}

int ValidArg(char *Arg) {
    int Long;
    char *Opt;

    ++Arg;
    if(*Arg == '-') {
        Long = 1;
        ++Arg;
    }
    
    for(int i=0; Options[i]; ++i) {
        Opt = Options[i];

        if(Long && !strcmp(Arg,Opt)) {
            return 1;
        } 
        
        if(ShortOpt[i] && *Arg == ShortOpt[i]) {
            return 1;
        }
    }
    return 0;
}

void ParseArgs(int argc, char **argv) {
    char *Arg;
    int Short;

    for(int i=1; i < argc; ++i) {
        Arg = argv[i];
    }
}