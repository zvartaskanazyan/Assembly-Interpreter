#pragma once
#include <string>

struct Token
{
	std::string command;
	std::string offset;
	std::string first;
	std::string second;

	Token(std::string first = " ", std::string offset = " ", std::string command = " ", std::string second = " ")
		: first(first)
		, command(command)
		, offset(offset)
		, second(second)
	{}
};
