/********************************************************\
File Name: exceptions_for_file.cpp
Author: Liri (4/4/2020)
Purpose: This file contain class of Exception_File_Not_Open,
			with the function that throw exception
			if fopen fail
\********************************************************/

#include "exceptions_for_file.h"

Exception_File_Not_Open::Exception_File_Not_Open(const char* new_file_name) 
{
	string file_name_new(new_file_name);
	file_name = file_name_new;
}

string Exception_File_Not_Open::what() throw ()
{
	string error_string;
	error_string = "Error - Opening file: " + file_name + " fail!";
	return error_string;
}