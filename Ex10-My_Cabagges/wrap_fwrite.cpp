/********************************************************\
File Name: wrap_fwirte.cpp
Author: Liri (4/4/2020)
Purpose: This file contain class of WrapFwrite, that inherits
			from WrapFopen with the functions that run
			fwrite with the given parameters, if the writing 
			fails than throw exception
\********************************************************/

#include "wrap_fwrite.h"

int WrapFwrite::write_to_file(const void * buffer,
							  size_t size,
							  size_t count,
							  FILE* fp)
{
	int return_value_of_fwrite = fwrite(buffer, size, count, fp);
	if (return_value_of_fwrite != count) {
		throw Exception_Write_File();
	}
	return return_value_of_fwrite;
}