#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

/**
 * Reads a file and stores the contents in a 
 * char array. File open/close, memory, and read
 * operations are checked.
 */
int read_file(char* filename, char** buffer) {
        FILE *file = fopen(filename, "r");

        if (file == NULL) {
                fclose(file);
                return -1;
        }

        fseek(file, 0L, SEEK_END);
        long size = ftell(file);
        fseek(file, 0L, SEEK_SET);

        *buffer = (char*)malloc(sizeof(char) * size);

        if (buffer == NULL) {
                fclose(file);
                return -1;
        }

        int numRead = fread(*buffer, sizeof(char), size, file);

        if (numRead != size) {
                fclose(file);
                return -1;
        }
        if (fclose(file) != 0) {
                return -1;
        }
        return size;
}

/**
 * Writes the buffer to a specified filename.
 * File open/close, and write operations are checked.
 */
int write_file(char* filename, char* buffer, int size) {
        FILE *wrtFile = fopen(filename, "w");

        if (wrtFile == NULL) {
                fclose(wrtFile);
                return -1;
        }

        for (int i = 0; i < size; i++) {
                fputc(buffer[i], wrtFile);
        }

        if (ferror(wrtFile) != 0) {
                fclose(wrtFile);
                return -1;
        }
        if (fclose(wrtFile) != 0) {
                return -1;
        }
        return 0;
}
