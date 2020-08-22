#pragma once
#include "instruction.h"

class Instructions {
public:
	static Instruction* CreateInstruction(CPU* c, const Token& token);
private:
	Instructions();
};