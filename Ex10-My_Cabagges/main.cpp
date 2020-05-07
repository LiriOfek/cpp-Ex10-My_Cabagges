/********************************************************\
File Name: main.cpp
Author: Liri (4/4/2020)
Purpose: This main file contain the main function that run classes that
			wrap fopen, wrap fwrite, and test their functionality
\********************************************************/

#include "wrap_fopen.h"
#include "wrap_fwrite.h"

const string FILE_NAME = "new_file.txt";
const char* OPENING_READ_MODE = "w";

int main() {
	/**
	* @brief  open file with WrapFile class, write to file with WrapFwrite 
	*			class, and catch the exceptions that thrown
	* @param  OUT - if exception thrown - EXIT_FAILURE, otherwise -
	*			  EXIT_SUCCESS
	* @return if exception thrown - EXIT_FAILURE, otherwise -
	*			  EXIT_SUCCESS
	* @note   open file, write to file, close in the end automatically,
	*			and catch exception if thrown
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
