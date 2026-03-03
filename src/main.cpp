#include <string>
#include <memory>
#include <filesystem>
#include <vector>

#include "string_charz.hpp"

int main(){
	/* Grab files */
	std::vector<std::string> files;	
	auto path_to_dir = "./test_files";
    
    /* Iterate through the directory and store file paths in vector */
	for(const auto& file : std::filesystem::directory_iterator(path_to_dir)){
		files.push_back(file.path());
	}
	
	/* Init counter */
	auto counter = std::make_unique<StringCharz>(files);  
}
