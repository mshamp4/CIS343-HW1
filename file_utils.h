#ifndef FILE_UTILS_H
#define FILE_UTILS_H

/**
 * This function reads a file and allocates memory 
 * for a buffer. It returns the size of the buffer
 * or -1 when an operation has failed.
 */
int read_file(char* filename, char** buffer);

/**
 * This function writes to a new file each time it 
 * is invoked. Returns 0 upon success and -1 upon failure.
 */
int write_file(char* filename, char* buffer, int size);

#endif /* FILE_UTILS_H */
