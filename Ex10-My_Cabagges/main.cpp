/********************************************************\
File Name: main.cpp
Author: Liri (4/4/2020)
Purpose: This main file contain the main function that run the class that
			wrap fopen and test it functionality
\********************************************************/

#include "wrap_fopen.h"

int main() {
	/**
	* @brief  open file with WrapFile class, catch the exceptions
	*			that thrown
	* @param  OUT - if fopen succeeded - EXIT_SUCCESS, otherwise - 
	*				EXIT_FAILURE 
	* @return if fopen succeeded - EXIT_SUCCESS, otherwise - 
	*			  EXIT_FAILURE 
	* @note   open file, close in the end, and catch exception if
	*			thrown
	* @author  Liri
	*/
	const string name_of_file = "file.txt";
	const char* opening_read_mode = "r";
	try {
		WrapFopen wrap_open_file(name_of_file, opening_read_mode);
		wrap_open_file.fopen_throw_exception_if_fail();
	}
	catch (Exception_File_Not_Open& e) {
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}