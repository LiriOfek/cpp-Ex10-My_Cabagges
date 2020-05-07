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

class WrapFread : public WrapFopen {
public:
	WrapFread(const string& new_file_name, 
			  const char* new_opening_mode) :
		WrapFopen(new_file_name, new_opening_mode) {
	}
};