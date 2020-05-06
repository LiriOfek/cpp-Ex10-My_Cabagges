/********************************************************\
File Name: wrap_fopen.cpp
Author: Liri (4/4/2020)
Purpose: This file contain class of WrapFopen, with the functions that 
			run fopen with the given parameters, if the opening is fails 
			than throw exception, and if the progrem end than close the
			file automatically
\********************************************************/

#include "wrap_fopen.h"

WrapFopen::WrapFopen(const string& new_file_name, 
					 const char* new_opening_mode){
	file_name = new_file_name.c_str();
	opening_mode = new_opening_mode;
}

FILE* WrapFopen::open_file() {
	file_pointer = fopen(file_name, opening_mode);
	/*to do - throw errors and change name of function!*/
	return file_pointer;
}