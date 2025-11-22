#include "string_charz.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <functional>

void StringCharz::characterize_file(const std::string& file_name)
{
	std::ifstream inputFile(file_name);

	if(!inputFile.is_open()) 
	{
		std::cerr << "[ERROR] Opening file: " << file_name << " in " << __func__ << std::endl;
		std::abort();
	}		

	/* File is open */
	/* Run suite of charz tests */
	/* TODO: Charz test suites */
}

/**
 * @FUNCTION: 	Top Level function call from constructor. 
 * @PARAM	Files - vector of paths to files to characterize 
 * @RETURNS 	VOID
 */
void StringCharz::get_charz_of(const std::vector<std::string> files)
{
	for(auto file : files) { 
		LOG(file); 
		characterize_file(file);
	} 
}
