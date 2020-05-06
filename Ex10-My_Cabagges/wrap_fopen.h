/********************************************************\
File Name: wrap_fopen.h
Author: Liri (4/4/2020)
Purpose: This header file contain class of WrapFopen, with the declaration 
			of functions that run fopen with the given parameters, if the 
			opening fails than throw exception, and if the progrem end 
			than close the file automatically
\********************************************************/

#pragma once

#include <iostream>
#include <string>

using namespace std;

/*class that wrap fopen, throw exception if the opening fail, and close the
	file automatically if the program end*/
class WrapFopen {
	const char* file_name;
	const char* opening_mode;
	FILE* file_pointer;
public:
	/**
	* @brief  create WrapFopen and set the name of the file and the
	*			opening mode
	* @param  IN const string& new_file_name - the new file name
	*		  IN const char* new_opening_mode - the opening mode
	* @return this function has no return value
	* @note   create WrapFopen and set the name of the file and the 
	*			opening mode
	* @author  Liri
	*/
	WrapFopen(const string& new_file_name,
			  const char* new_opening_mode);

	FILE* open_file();

};