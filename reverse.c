#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

/**
 * This program takes an input file, reverses 
 * the contents and writes it to an output file.
 */
int main(int argc, char** argv){
        if (argc != 3) {
                fprintf(stderr, "Error! invalid arguments\nUsage: %s [input file] "
                "[output file]\n", argv[0]);
                return 1;
        }

        char* buffer;
        int size = read_file(argv[1], &buffer);

        if (size == -1) {
                fprintf(stderr, "Error reading file!\n");
                free(buffer);
                return 1;
        }

        // Put this into a seperate method              
        int end = size - 1;
        int start = 0;

        while (end > start) {
                char temp = buffer[end];
                buffer[end] = buffer[start];
                buffer[start] = temp;
                end--;
                start++;
        }

        int success = write_file(argv[2], buffer, size);

        if (success != 0) {
                fprintf(stderr, "Error writing file!\n");
                free(buffer);
                return 1;
        }

        free(buffer);
        return 0;
}
