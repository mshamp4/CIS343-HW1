#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int read_file(char* filename, char** buffer) {
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
                return -1;
        }
		
        fseek(file, 0L, SEEK_END);
        long size = ftell(file);
        fseek(file, 0L, SEEK_SET);
		
//		printf("Size of file: %ld", size);

        // TO-DO: make sure memory call completes successfully
        *buffer = (char*)malloc(sizeof(char) * size);

        fread(*buffer, sizeof(char), size, file);

        if (fclose(file) != 0) {
			return -1;
        }       
        return size;
}

int write_file(char* filename, char* buffer, int size) {
        FILE *wrtFile = fopen(filename, "w");
		size = size;
		
		printf("Size: %i", size);
		
		int count = 0;
		while (count < size) {
			fputc(buffer[count], wrtFile);
			count++;
		}

		if (fclose(wrtFile) != 0) {
			return -1;
        }
        return 0;
}
