#ifndef _UTIL_H_
#define _UTIL_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <sys/types.h>
#include <errno.h>


unsigned int split(const std::string& in, std::vector<std::string>& out, const std::string& seperator);

#endif

