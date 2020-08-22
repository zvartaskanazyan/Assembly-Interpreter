#pragma once
#include <string>
#include <vector>
#include "token.h"

class Conditions
{
public:

	Conditions() {}
	static unsigned regIndex(const std::string& vec);
	static bool isRegister(const std::string& vec);
	static bool areEquals(const std::string& vec1, const std::string& vec2);
};



