#include "./path.h"

char* CreatePath(int size) {
    char *path = malloc(STRING_SIZE);
    char *size_to_string = malloc(STRING_SIZE);

    snprintf( size_to_string, STRING_SIZE, "%d", size);
    
    strcpy(path, "dist/");
    strcat(path, size_to_string);
    strcat(path, "x");
    strcat(path, size_to_string);
    strcat(path, ".png");

    return path;
}