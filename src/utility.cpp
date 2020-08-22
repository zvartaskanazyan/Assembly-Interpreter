#include "utility.h"
#include <sstream>

bool Conditions::isRegister(const std::string& vec)
{
	if (vec.at(0) != 'R') return false;
	for (auto i = vec.begin() + 1; i != vec.end(); ++i)
	{
		if (!isdigit(*i))
			return false;
	}
	return true;
}

unsigned Conditions::regIndex(const std::string& vec)
{
	std::stringstream read(vec);
	int n;
	while (read) {
		if (isalpha(read.peek()))
			read.ignore();
		if (isdigit(read.peek()))
		{
			read >> n;
		}
	}
	return n;
}

bool Conditions::areEquals(const std::string& vec1, const std::string& vec2)
{
	return vec1 == vec2;
}