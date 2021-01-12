#pragma once

#include <iostream>

/*
log
end
logend
logerror
logwarning
*/

#define LOG std::cout <<
#define END << "\n"
#define LOGEND std::cout << "\n";
#define LOGERROR(x) std::cout << "Error: " << x << " " << __LINE__ << "\n"; exit(0);
#define LOGWARNING(x) std::cout << "Warning: " << x << " " << __LINE__ << "\n";