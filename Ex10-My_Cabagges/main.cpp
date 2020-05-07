/********************************************************\
File Name: main.cpp
Author: Liri (4/4/2020)
Purpose: This main file contain the main function that run classes that
			wrap fopen, wrap fwrite, and test their functionality
\********************************************************/

#include "wrap_fopen.h"
#include "wrap_fread.h"

int size_of_file(FILE* file_pointer);
void test_read_from_file_throw_exception_if_fail(WrapFread wrap_file,
												 char buffer[]);

const string FILE_NAME = "file.txt";
const char* OPENING_READ_MODE = "r";
const int MAX_SIZE_OF_BUFFER = 100;
const char END_OF_STRING = '\0';

int main() {
	const string name_of_file = FILE_NAME;
	const char* opening_read_mode = OPENING_READ_MODE;
	WrapFread wrap_file(name_of_file, opening_read_mode);
	char buffer[MAX_SIZE_OF_BUFFER];

	try {
		test_read_from_file_throw_exception_if_fail(wrap_file,
												    buffer);
	}
	catch (Exception_File_Not_Open& e) {
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (Exception_Read_File& e) {
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

void test_read_from_file_throw_exception_if_fail(WrapFread wrap_file, 
											     char buffer[]) {
	/**
	* @brief  run the functions that open the given file and read it 
	*			to the given buffer
	* @param  IN WrapFread wrap_file - the given wrap file, to read from
	*		  IN char buffer[] - the buffer to write there what that in the file
	* @return this function has no return value
	* @note   open file, read from it to the buffer, and close the file
	*			automatically in the end of the program
	* @author  Liri
	*/
	FILE* file_pointer;
	file_pointer = wrap_file.fopen_throw_exception_if_fail();
	int count = size_of_file(file_pointer);
	wrap_file.read_from_file_throw_exception_if_fail(buffer,
													 sizeof(char),
												     count,
													 file_pointer);
	buffer[count] = END_OF_STRING;
	std::cout << buffer;
}

int size_of_file(FILE* file_pointer) {
	/**
	* @brief  calculate the length of the file in chars
	* @param  IN FILE* file_pointer - the file pointer
	*		  OUT int - the length of the files in chars
	* @return the length of the file in chars
	* @note   rewind the file pointer to the beginning of the file
	* @author  Liri
	*/
	int length = 0;
	while (feof(file_pointer) == 0) {
		char c = getc(file_pointer);
		if (c != EOF) {
			length++;
		}
	}
	rewind(file_pointer);
	return length;
}
