#pragma once
#include <map>
#include <string>
#include <vector>

class Program;

class CPU
{
public:
	CPU();
	void run();
	void incrementPC() { ++program_counter; }
	unsigned getPC() const { return program_counter; }
	void stopRunning() { running = false; }
	void updatePC(const std::string& label);
	bool isRunning() const { return running; }
	void loadProgram(const std::string& filename);
	int  getRegisterValue(const std::string& name) const;
	void setRegisterValue(const std::string& name, int value);
	void setLabel(const std::string& label, unsigned line_number);
	std::vector<std::string> getRegs(unsigned from, unsigned  to);
	std::vector<std::pair<std::string, int>> getRegisters();//helper for displaying

private:

	unsigned program_counter;
	bool running;
	Program* program;
	char* stackPointer;
	std::vector<char> stack;
	std::map<std::string, unsigned> labels;
	std::map<std::string, unsigned char> registers;
	std::map<std::string, unsigned char> address_registers;
};

