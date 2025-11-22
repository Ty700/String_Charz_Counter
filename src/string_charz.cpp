#include "string_charz.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

void String_Charz::characterize_file(const std::string& file_name)
{
	std::ifstream inputFile(file_name);

	if(!inputFile.is_open()) 
	{
		std::cerr << "[ERROR] Opening file: " << file_name << " in " << __func__ << std::endl;
		return;
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
void String_Charz::get_charz_of(const std::vector<std::string> files)
{
	#ifdef DEBUG 
		std::cout << "IN GET_CHARZ_OF " << std::endl;
		for(auto file : files) { std::cout << file << std::endl; }
	#endif /* DEBUG */
		
	for( auto file : files) {
		characterize_file(file);
	}
}
