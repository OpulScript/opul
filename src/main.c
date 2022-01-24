#include <stdio.h>

#include "opul.h"

// entry point
int main(int argc, char **argv){
    // if no args
    if(argc == 1){
        printf("\x1b[31m\x1b[1mError\x1b[0m: no input files\n");
        printf("Use -h or --help to show a help page\n");
        return 1;
    }

    // TODO: Code a CLI argument parser

    // TODO: Read source file content

    opul_compile("");

    return 0;
}