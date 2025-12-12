#include "string_charz.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

std::string filterFileName(const std::string& file_name)
{
	auto idx = file_name.find(".txt");

	if (idx == std::string::npos)
	{
		return file_name + "_charz.txt";
	}

	return file_name.substr(0, idx) +  "_charz.txt";
}

std::ofstream createCharzFile(const std::string& file_name)
{
	const std::string outfile_name = filterFileName(file_name); 
	
	std::ofstream outputFile(outfile_name);

	if(!outputFile.is_open())
	{
		std::cerr << "[ERROR] Creating  file: " << file_name << " in " << __func__ << std::endl;
		std::abort();
	}

	return outputFile;
}

std::string readFile(std::ifstream& infile)
{
	std::string fileContents{""};
	std::string currLineContents{""};

	while(std::getline(infile, currLineContents))
	{
		fileContents += currLineContents;
		fileContents += '\n';
	}

	return fileContents;
}

void StringCharz::characterizeFile(const std::string& file_name)
{
	/* Open the file */
	std::ifstream inputFile(file_name);
	
	if(!inputFile.is_open()) 
	{
		std::cerr << "[ERROR] Opening file: " << file_name << " in " << __func__ << std::endl;
		std::abort();
	}		
	
	/* Read contents of inputFile & assign it to str */
	std::string str = readFile(inputFile);

	/* Debug */
	LOG(str);
	
	/* Create charz output file */
	std::ofstream outFile = createCharzFile(file_name);

	/* File is open */
	/* Run suite of charz tests */
	for(auto& op : operations)
		op(str, outFile);
	
	/* Close file */
	inputFile.close();
}

/**
 * @FUNCTION: 	Top Level function call from constructor. 
 * @PARAM	Files - vector of paths to files to characterize 
 * @RETURNS 	VOID
 */
void StringCharz::getCharzOf(const std::vector<std::string> files)
{
	for(auto& file : files) { 
		LOG(file);
		characterizeFile(file);
	} 
}

void StringCharz::countWords(const std::string& str, std::ostream& outFile)
{
	LOG(str);
}
void StringCharz::setupOperations()
{
	operations.push_back([this](const std::string& s, std::ostream& o){ countWords(s, o); });
	// operations.push_back([this](const std::string& s, std::ostream o){});
	// operations.push_back([this](const std::string& s, std::ostream o){});
	// operations.push_back([this](const std::string& s, std::ostream o){});
	// operations.push_back([this](const std::string& s, std::ostream o){});
}
