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
		
		if (size == -1) {
			fprintf(stderr, "Error reading file!\n");
			return 1;
		}
		
//		char* endBuff = &buffer[size - 1];
		
//		printf("Char:%c", *endBuff);

//        for (int i = (size - 1); i >= 0; i--) {
//                printf("%c", buffer[i]);
//        }

		int end = size - 1;
		int start = 0;
		
		while (end > start) {
			char temp = buffer[end];
			buffer[end] = buffer[start];
			buffer[start] = temp;
			end--;
			start++;
		}
		
//		for (int i = 0; i < size; i++) {
//			printf("%c", buffer[i]);
//		}

		write_file(argv[2], buffer, size);

        free(buffer);
        return 0;
}
