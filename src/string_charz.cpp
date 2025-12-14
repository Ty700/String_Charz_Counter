#include "string_charz.hpp"

#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

static std::string filterFileName(const std::string& file_name)
{
	auto idx = file_name.find(".txt");

	if (idx == std::string::npos)
	{
		return file_name + "_charz.txt";
	}

	return file_name.substr(0, idx) +  "_charz.txt";
}

static std::ofstream createCharzFile(const std::string& file_name)
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

static std::string readFile(std::ifstream& infile)
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
	/* The cow jumped over the moon -> Returns 6 */
	LOG(str);
	
	auto word_count = 0;
	bool in_word = false;

	for(size_t i = 0; i < str.length(); i++)
	{
		/* Is character in the alphabet? */
		if(std::isalpha(str[i]))
		{
			if(!in_word)
			{
				in_word = true;
				word_count += 1;
			}
		} 
		else 
		{
			in_word = false;
		}
	}

	std::string res = "Total Words: " + std::to_string(word_count) + '\n';

	outFile << res;
}

void StringCharz::countLines(const std::string& str, std::ostream& outFile)
{
	auto line_count = 0;
	for(size_t i = 0; i < str.length(); i++)
	{
		if(str[i] == '\n')
			line_count += 1;
	}

	std::string res = "Total Lines: " + std::to_string(line_count) + '\n';

	outFile << res;
}

void StringCharz::countSpaces(const std::string& str, std::ostream& outFile)
{
	auto space_count = 0;
	for(size_t i = 0; i < str.length(); i++)
	{
		if(str[i] == ' ')
			space_count += 1;
	}

	std::string res = "Total Spaces: " + std::to_string(space_count) + '\n';

	outFile << res;
}

void StringCharz::calLongestWord(const std::string& str, std::ostream& outFile)
{
	/* "The cow jumped over the moon"	-> Outputs "jumped" 		*/
	/* "The Cow" 				-> Outputs "The Cow" 		*/
	/* "The moose jumps fast" 		-> Outputs "Moose Jumps" 	*/
	/* "The the the the the" 		-> Outputs "The" 		*/ 
	LOG(str);
	
	bool in_word = false;
	
	auto curr_word_start = 0;
	auto curr_word_len = 0;
	auto max_word_len = 0;

	/* Vector as there can be words with matching len that are max len*/
	std::vector<std::string> longest_word = {};

	for(size_t i = 0; i < str.length(); i++)
	{
		/* Is character in the alphabet? */
		if(std::isalpha(str[i]))
		{
			if(!in_word)
			{
				in_word = true;
				curr_word_len = 1;
				curr_word_start = i;
			}
			else 
			{
				curr_word_len += 1;
			} 
		}
		else /* Hit end of a word */
 		{
			if(in_word)
			{

				if(curr_word_len > max_word_len)
				{
					/* Overwrite previous max data */
					max_word_len = curr_word_len;

					/* Found new longest word length, flush vector and save word */
					longest_word.clear();
					longest_word.push_back(str.substr(curr_word_start, curr_word_len));
				}
				
				/* Covers words that are the same len and max len of str */
				else if(curr_word_len == max_word_len)
				{
					/* TODO! DUPLICATE WORDS SHOULD NOT BE ADDED TO THE LONGEST WORD VEC */
					longest_word.push_back(str.substr(curr_word_start, curr_word_len));
				}
				
				/* Reset */
				in_word = false;
				curr_word_len = 0;
			}
		}
	}
	
	/* BUG FIX!!! 
	 * IF FILE DOESN'T END WITH A NEW LINE THEN LAST WORD WON'T BE PROCESSED
	 */
	if(in_word && curr_word_len > 0)
	{
		/* Save word length */
		if(curr_word_len > max_word_len)
		{
			/* Overwrite previous max data */
			max_word_len = curr_word_len;

			/* Found new longest word length, flush vector and save word */
			longest_word.clear();
			longest_word.push_back(str.substr(curr_word_start, curr_word_len));
		}
		
		/* Covers words that are the same len and max len of str */
		else if(curr_word_len == max_word_len)
		{
			longest_word.push_back(str.substr(curr_word_start, curr_word_len));
		}

	}

	/* Output to file */
	/* Longest word found? */
	if(!longest_word.empty())
	{
		/* Prefix to output */
		std::string res = "Longest Word(s): ";
	
		/* Were there words with the same length that were also the max length? */
		if (longest_word.size() > 1)
		{	
			for(size_t i = 0; i < longest_word.size(); i++)
			{
				if(i == longest_word.size() - 1)
				{
					res += longest_word.at(i);
				}
				else 
				{
					res += longest_word.at(i) + ", ";
				}
			}
		}
		else /* Single longest word */
		{	
			res += longest_word.at(0);
		}

		outFile << res << '\n';
	}
	else 
	{
		outFile << "Empty File.\n";
	}
}

void StringCharz::countVowels(const std::string& str, std::ostream& outFile)
{
 
}

void StringCharz::countConsonants(const std::string& str, std::ostream& outFile)
{

}

void StringCharz::setupOperations()
{
	/* IDEAS: 
	 *	Count words 
	 *	Count lines 
	 *	Count spaces 
	 *	Calculate longest word 
	 *	Number of Vowels
	 *	Number of consonant 
	 */
	operations.push_back([this](const std::string& s, std::ostream& o){ countWords(s, o); });
	operations.push_back([this](const std::string& s, std::ostream& o){ countLines(s, o); });
	operations.push_back([this](const std::string& s, std::ostream& o){ countSpaces(s,o); });
	operations.push_back([this](const std::string& s, std::ostream& o){ calLongestWord(s,o); });
	operations.push_back([this](const std::string& s, std::ostream& o){ countVowels(s, o); });
	operations.push_back([this](const std::string& s, std::ostream& o){ countConsonants(s, o); });

}
