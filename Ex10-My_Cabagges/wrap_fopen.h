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

class WrapFopen {
	const char* file_name;
	const char* opening_mode;
public:
	WrapFopen(const string& new_file_name,
			  const char* new_opening_mode);
};