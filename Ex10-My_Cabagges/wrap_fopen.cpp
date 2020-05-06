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
					 const char* new_opening_mode) :
	Exception_File_Not_Open(new_file_name.c_str()) 
{
	file_name = new_file_name.c_str();
	opening_mode = new_opening_mode;
}

FILE* WrapFopen::fopen_throw_exception_if_fail() 
{
	file_pointer = fopen(file_name, opening_mode);
	if (!file_pointer) {
		throw Exception_File_Not_Open(file_name);
	}
	return file_pointer;
}

WrapFopen::~WrapFopen() 
{
	if (file_pointer != NULL) {
		fclose(file_pointer);
	}
}