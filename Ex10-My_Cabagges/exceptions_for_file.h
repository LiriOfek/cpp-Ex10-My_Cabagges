/********************************************************\
File Name: exceptions_for_file.h
Author: Liri (4/4/2020)
Purpose: This header file contain class of Exception_File_Not_Open,
			with the declaration of function that throw exception
			if fopen fail
\********************************************************/

#pragma once

#include <iostream>
#include <exception>
#include <string>

using namespace std;

/*class that throw exception if there was a failure during fopen*/
class Exception_File_Not_Open : public exception {
	string file_name;
public:
	Exception_File_Not_Open(const char* new_file_name);
	/**
	* @brief  create Exception_File_Not_Open and set the name of the file
	* @param  IN const const char* new_file_name - the new file name
	* @return this function has no return value
	* @note   create Exception_File_Not_Open and set the name of the file 
	* @author  Liri
	*/

	string what() throw ();
	/**
	* @brief  throw error message, contain the name of the file
	* @params OUT string the error massage, contain the name of the file
	* @return the error message, contain the name of the file
	* @note   throw error message, contain the name of the file
	* @author  Liri
	*/

};