#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int read_file(char* filename, char** buffer) {
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
                return 1;
        }
        fseek(file, 0L, SEEK_END);
        long size = ftell(file);
        fseek(file, 0L, SEEK_SET);
        printf("%lu", sizeof(char));
//      printf("%li\n", size);
//      int size1 = sizeof(char) * size;
//      printf("%i\n", size1);
        // TO-DO: make sure memory call completes successfully
        *buffer = (char*)malloc(sizeof(char) * size);

//      char value = NULL;

        fread(*buffer, sizeof(char), size, file);


//      for (int i = 0; value != EOF; i++) {
//              value = fgetc(file);
//              printf("%c", value);
//              buffer[i] = &value; // error here
//      }

        if (fclose(file) != 0) {
		return 1;
        }       
        return size;
}

int write_file(char* filename, char* buffer, int size) {
        FILE *wrtFile = fopen(filename, "w");
//      printf("%i", size);
//      size = size - 2;
        while (size >= 0) {
                fputc(buffer[size], wrtFile);
                size--;
        }
//      for (int i = size; size > 0; i--) {
//              printf("%i", i);
//              fputc(buffer[10], wrtFile);
//      }


        return 0;
}


