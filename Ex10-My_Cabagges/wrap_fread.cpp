/********************************************************\
File Name: wrap_fread.cpp
Author: Liri (4/4/2020)
Purpose: This file contain class of WrapFread, that inherits
			from WrapFopen with the functions that run
			fread with the given parameters, if the reading fails
			than throw exception
\********************************************************/

#include "wrap_fread.h"

int WrapFread::read_from_file(void* buffer, 
							  size_t size, 
							  size_t count, 
							  FILE* fp)
{
	int return_value_of_fread = fread(buffer, 
									  size, 
									  count, 
									  fp);
	if (return_value_of_fread != count) {
		throw Exception_read_file();
	}
	return return_value_of_fread;
}