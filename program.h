#pragma once
#include <vector>
#include "arithmetic_logic_unit.h"
#include "cpu.h"

class Program
{
public:

	Program(CPU* c, const std::string& filename);
	void execute();

private:
	void init(CPU* c, const std::string& file_name);
	std::vector<Instruction*> instructions;
	CPU* computer;
};

