#include <stdio.h>
#include <stdlib.h>

char *readfile(FILE *f){

    // invalid file or fseek() failed
    if(f == NULL || fseek(f, 0, SEEK_END)){
        return NULL;
    }

    long length = ftell(f);
    rewind(f);

    // ftell() failed or file too long
    if(length == -1 || (unsigned long) length >= 1073741824){
        return NULL;
    }

    size_t ulength = (size_t)length;
    char *buffer = malloc(ulength + 1);

    // allocation error or read inclomplete
    if(buffer == NULL || fread(buffer, 1, ulength, f) != ulength){
        free(buffer);
        return NULL;
    }
    buffer[ulength] = '\0'; // null-terminator

    return buffer;
}