#include "file_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int read_file(char* filename, char **buffer) {
    FILE* file1;
    file1 = fopen(filename, "r");
    // error handling to make sure file1 exists & is non-null
    if (file1 == NULL) {
        fprintf(stderr, "File could not be opened.");
        return -1;
    }

    //get file size
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    *buffer = malloc(size);
    fread(*buffer, 1, size, file1);
    fclose(file1);
    return size;
}

int write_file(char* filename, char*buffer, int size) {
    FILE* file2;
    file2 = fopen(filename, "w");
    // error handling to make sure file2 exists & is non-null
    if (file2 == NULL) {
        fprintf (stderr, "File could not be opened.");
        return -1;
    }
    // written with help from Eris
    // write from read_file buffer into file2
    for (int c = size - 1; c >= 0; c--) {
        char *x = buffer + c;
        fprintf(file2, "%c", *x);
    }
    fclose(file2);
    return 1;
}
