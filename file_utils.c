#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int read_file(char* filename, char** buffer) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		return 1;
	}
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fseek(file, 0, SEEK_SET);
	// TO-DO: make sure memory call completes successfully
	*buffer = (char*)malloc(sizeof(char) * size + 1);
 
	char value = NULL;
	for (int i = 0; value != EOF; i++) {
		value = fgetc(file);
		printf("%c", value);
		buffer[i] = &value; // error here
	}

	if (fclose(file) != 0) {
		return 1;
	}
	return 0;
}

int write_file(char* filename, char* buffer, int size) {
	return 0;
}
