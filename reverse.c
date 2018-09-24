#include "file_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    char* buffer;
    char* file1;
    char* file2;
    int fileSize;

    file1 = argv[1];
    file2 = argv[2];

    // read & write file
    // written with help from Eris
    fileSize = read_file(file1, &buffer);
    write_file(file2, buffer, fileSize);

    // free memory allocated
    free(buffer);

    return 0;
}
