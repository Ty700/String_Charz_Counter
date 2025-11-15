#pragma once 

#include <stdint.h>
#include <unordered_map>

class String_Charz {
	public:
		String_Charz() {};
		~String_Charz() {};
		int get_stat(const char& key) {return charz_stats[key]; }

	private:
		std::unordered_map<char, int> charz_stats {};
};
