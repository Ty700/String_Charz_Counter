#include <iostream>
#include <fstream>
#include <memory>
#include <filesystem>
#include <vector>

#include "string_charz.hpp"

int main(){
	/* Init counter */
	auto counter = std::make_unique<String_Charz>(); 
	
	/* Grab files */
	std::vector<std::string> files;	
	auto path_to_dir = "./test_files";

	for(const auto& file : std::filesystem::directory_iterator(path_to_dir)){
		files.push_back(file.path());
	}
}
