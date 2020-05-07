/********************************************************\
File Name: wrap_fwirte.h
Author: Liri (4/4/2020)
Purpose: This header file contain class of WrapFwrite, that inherits 
			from WrapFopen with the declaration of functions that run 
			fwrite with the given parameters, if the writing fails 
			than throw exception
\********************************************************/

#pragma once

#include "wrap_fopen.h"
#include <cstdio>

/*class that wrap fwrite, inherits from WrapFopen,
	throw exception if writing fail*/
class WrapFwrite : public WrapFopen {
public:
	WrapFwrite(const string& new_file_name, 
			   const char* new_opening_mode) :
		WrapFopen(new_file_name, new_opening_mode) {
	}
	/**
	* @brief  create WrapFwriten and set the name of the file and the
	*			opening mode, by the constructor in WrapFopen
	* @param  IN const string& new_file_name - the new file name
	*		  IN const char* new_opening_mode - the opening mode
	* @return this function has no return value
	* @note   create WrapFwritten and set the name of the file and the
	*			opening mode
	* @author  Liri
	*/

};