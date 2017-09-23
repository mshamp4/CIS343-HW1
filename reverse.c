#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int main(int argc, char** argv){
        if (argc != 3) {
                fprintf(stderr, "Error! invalid arguments\nUsage: %s [input file] "
                "[output file]\n", argv[0]);
                return 1;
        }

        char* buffer;
        int size = read_file(argv[1], &buffer);

        for (int i = size; i >= 0; i--) {
                printf("%c", buffer[i]);
        }

        write_file(argv[2], buffer, size);

        free(buffer);
        return 0;
}
