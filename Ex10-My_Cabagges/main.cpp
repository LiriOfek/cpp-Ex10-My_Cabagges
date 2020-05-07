/********************************************************\
File Name: main.cpp
Author: Liri (4/4/2020)
Purpose: This main file contain the main function that run classes that
			wrap fopen, wrap fwrite, and test their functionality
\********************************************************/

#include "wrap_fopen.h"
#include "wrap_fwrite.h"

const string FILE_NAME = "file.txt";
const char* OPENING_READ_MODE = "r";

int main() {
	/**
	* @brief  open file with WrapFile class, write to file with WrapFwrite 
	*			class, and catch the exceptions that thrown
	* @param  OUT - if exception thrown - EXIT_SUCCESS, otherwise -
	*				EXIT_FAILURE
	* @return if exception thrown - EXIT_SUCCESS, otherwise -
	*			  EXIT_FAILURE
	* @note   open file, write to file, close in the end, and catch exception 
	*			if thrown
	* @author  Liri
	*/
	const string file_name = FILE_NAME;
	const char* opening_write_mode = OPENING_READ_MODE;
	WrapFwrite wrap_file(file_name, opening_write_mode);
	FILE* fp;
	char buffer[] = "New file\nHello";

	try {
		fp = wrap_file.fopen_throw_exception_if_fail();
		wrap_file.write_to_file_throw_exception_if_fail(buffer,	
														sizeof(char),
														sizeof(buffer), 
														fp);
	}
	catch (Exception_File_Not_Open& e) {
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (Exception_Write_File& e) {
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
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
