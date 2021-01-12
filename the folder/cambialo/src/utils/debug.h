#pragma once

#include <iostream>

#define LOG  std::cout <<
#define END  << "\n"
#define ENDL "\n"
#define LOGEND std::cout << "\n";
#define LERROR(x) std::cout << "Error: || " << x << " || line: " << __LINE__ << "\n"; exit(0);
#define LWARNING(x) std::cout << "Warning: || " << x << " || line: " << __LINE__ << "\n";;