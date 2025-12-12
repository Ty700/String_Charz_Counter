#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>

#include "util.hpp"

class StringCharz {
	public:
		StringCharz(const std::vector<std::string> v) : files{v}
		{	
			#ifdef DEBUG 
				for(auto file : files){ LOG(file); }
			#endif /* DEBUG */
			setupOperations();
			getCharzOf(files);
		};

		~StringCharz() {};
	
	private:
		/* Member */
		const std::vector<std::string> files {};
		std::vector<std::function<void(const std::string& str, std::ofstream& outfile)>> operations;
	
		/* Methods */
		void setupOperations();
		void getCharzOf(const std::vector<std::string> files);
		void characterizeFile(const std::string& file_name);

		/* Operations */
		void countWords(const std::string& str, std::ostream& outFile);
};
