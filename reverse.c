#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int main(int argc, char** argv){
	if (argc != 3) {
		fprintf(stderr, "Error! invalid arguments\nUsage: %s [input file] " 
		"[output file]", argv[0]);
		return 1;
	}	
	
	char* buffer;
	read_file(argv[1], &buffer);
	
	free(buffer);
	//write_file(char* filename, char* buffer, int size);
	
	return 0;
}
