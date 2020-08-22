#include "program.h"
#include "cpu.h"
#include "Exception.h"
#include <iostream>
#include <sstream>
#include <vector>

CPU::CPU()
{
	//initialize general-purpose registers
	for (size_t i = 0; i < 64; ++i) {
		std::stringstream str;
		str << "R" << i;
		registers[str.str()] = 0;
	}
	//initialize address registers
	for (size_t i = 0; i < 4; ++i) {
		std::stringstream str;
		str << "A" << i;
		address_registers[str.str()] = 0;
	}
}

void CPU::loadProgram(const std::string& filename)
{
	program = new Program(this, filename);
	program_counter = 0;
	running = true;
}

void CPU::run()
{
	program->execute();
}

void CPU::updatePC(const std::string& label)
{
	if (labels.find(label) == labels.end()) {
		throw Lable_Not_Found();
	}

	program_counter = labels[label];
	running = true;
}

int CPU::getRegisterValue(const std::string& name) const
{
	return registers.at(name);
}

void CPU::setRegisterValue(const std::string& name, int value)
{
	registers[name] = value;
}

void CPU::setLabel(const std::string& label, unsigned line_number)
{
	labels[label] = line_number;
}

std::vector<std::string> CPU::getRegs(unsigned from, unsigned to)
{
	std::vector<std::string> temp;
	for (unsigned i = from; i < to; ++i)
	{
		std::stringstream str;
		str << "R" << i;
		temp.push_back(str.str());
	}
	return temp;
}

std::vector<std::pair<std::string, int>> CPU::getRegisters() {
	std::vector<std::pair<std::string, int >> temp;

	for (auto i = 0; i < registers.size(); ++i) {
		std::stringstream str;
		str << "R" << i;
		temp.push_back(make_pair(str.str(), registers[str.str()]));
	}
	return temp;
}


