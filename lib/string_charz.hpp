#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class String_Charz {
	private:
		enum keys {
			WORDS,
			CHARACTERS,
			LINES,
			WHITESPACES
		};

	public:
		String_Charz(const std::vector<std::string> v) : files{v}
		{	
			#ifdef DEBUG 
			 std::cout << "[DEBUG] Files: \n";

			 for(auto file : files){
				 std::cout << "[DEBUG]\t" << file << "\n";
			 }

			 std::cout << std::endl;
			#endif /* DEBUG */
			
			get_charz_of(files);
		};

		~String_Charz() {};
	
	private:
		const std::vector<std::string> files {};
		std::unordered_map<keys, int> charz_stats{};
		int get_stat(const keys& key) { return charz_stats[key]; }
		void get_charz_of(const std::vector<std::string> files);
		void characterize_file(const std::string& file_name);
};
