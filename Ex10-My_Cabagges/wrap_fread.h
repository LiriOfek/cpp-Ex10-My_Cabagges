/********************************************************\
File Name: wrap_fread.h
Author: Liri (4/4/2020)
Purpose: This header file contain class of WrapFread, that inherits
			from WrapFopen with the declaration of functions that run
			fread with the given parameters, if the reading fails
			than throw exception
\********************************************************/

#pragma once

#include "wrap_fopen.h"
#include <cstdio>

/*class that wrap fread, inherits from WrapFopen,
	throw exception if reading fail*/
class WrapFread : public WrapFopen {
public:
	WrapFread(const string& new_file_name, 
			  const char* new_opening_mode) :
		WrapFopen(new_file_name, new_opening_mode) {
	}
	/**
	* @brief  create WrapFread and set the name of the file and the
	*			opening mode, by the constructor in WrapFopen
	* @param  IN const string& new_file_name - the new file name
	*		  IN const char* new_opening_mode - the opening mode
	* @return this function has no return value
	* @note   create WrapFread and set the name of the file and the
	*			opening mode
	* @author  Liri
	*/

	int read_from_file_throw_exception_if_fail(void* buffer,
											   size_t size, 
											   size_t count, 
											   FILE* fp);
	/**
	* @brief  read from the file with fread, and if there was an error throw
	*			unique exception
	* @param  OUT int - the return value of fread()
	* @return the return value of fread()
	* @note   read the file, and if there was an error throw unique
	*			exception
	* @author  Liri
	*/
};