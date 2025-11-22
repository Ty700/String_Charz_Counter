#pragma once 
#include <iostream>
#include <filesystem>

#define __FILENAME__ (std::filesystem::path(__FILE__).filename().string().c_str())

#ifdef DEBUG 
	#define LOG(msg) \
		std::cout << "[DEBUG: " << __FILENAME__ << 	\
			   ": " << __LINE__ << 	\
			   " | " << __func__ << 	\
			   "] " << msg << std::endl;	

#else
	#define LOG(msg)
#endif /* DEBUG */


