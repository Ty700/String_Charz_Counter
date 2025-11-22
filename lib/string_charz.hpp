#pragma once 
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "util.hpp"

class StringCharz {
	private:
		enum keys {
			WORDS,
			CHARACTERS,
			LINES,
			WHITESPACES
		};

	public:
		StringCharz(const std::vector<std::string> v) : files{v}
		{	
			for(auto file : files){ LOG(file); }
			get_charz_of(files);
		};

		~StringCharz() {};
	
	private:
		const std::vector<std::string> files {};
		std::unordered_map<keys, int> charz_stats{};
		int get_stat(const keys& key) { return charz_stats[key]; }
		void get_charz_of(const std::vector<std::string> files);
		void characterize_file(const std::string& file_name);
};
