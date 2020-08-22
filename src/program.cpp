#include "token.h"
#include "program.h"
#include "exception.h"
#include "instructionsSet.h"
#include <fstream>
#include <cstring>
#include <iostream>

Program::Program(CPU* c, const std::string& file_name)
{
	computer = c;
	init(computer, file_name);
}

void Program::init(CPU* c, const std::string& file_name) {
	Instructions* factory;
	std::vector<Token> vec;
	std::string instruction;
	std::ifstream inFile;
	Token reg;
	auto line_number = 0;

	inFile.open(file_name);
	try {
		if (!inFile.is_open())
		{
			throw File_Doesnt_Open();
		}
	}
	catch (File_Doesnt_Open& f)
	{
		std::cout << f.what() << std::endl;
		exit(1);
	}
	while (std::getline(inFile, instruction))
	{
		unsigned first = instruction.find(' ');
		unsigned second = instruction.find(' ', first + 1);
		unsigned middle = instruction.find(' ', second + 1);
		unsigned last = instruction.find('\n');

		if (instruction == "")
			continue;
		if (instruction.back() == ':') {
			computer->setLabel(instruction.substr(0, instruction.find(':')), line_number);
			++line_number;
		
		} else {
			if (middle != last)	{
				std::string str1 = instruction.substr(0, first);
				std::string str2 = instruction.substr(first + 1, second - first - 1);
				std::string str3 = instruction.substr(second + 1, middle - second - 1);
				std::string str4 = instruction.substr(middle + 1, last - middle);

				reg.command = str1;
				reg.offset = str2;
				reg.first = str3;
				reg.second = str4;
				vec.push_back(reg);
				++line_number;
			} else {
				std::string str1 = instruction.substr(0, first);
				std::string str2 = instruction.substr(first + 1, second - first - 1);
				std::string str3 = instruction.substr(second + 1, middle - second - 1);

				reg.command = str1;
				reg.offset = str2;
				reg.first = str3;
				reg.second = "";
				vec.push_back(reg);
				++line_number;
			}
		}
	}

	for (size_t i = 0; i < vec.size(); ++i) 
	{
		instructions.push_back(factory->CreateInstruction(c, vec[i]));
	}
}

void Program::execute() {
	while (computer->isRunning() && computer->getPC() < instructions.size())
	{
		instructions.at(computer->getPC())->execute();
		computer->incrementPC();
	}
}