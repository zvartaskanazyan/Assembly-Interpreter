#pragma once
#include "instruction.h"
#include "token.h"

class Assign : public Instruction
{
public:

	Assign(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class Load :public Instruction
{
public:

	Load(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};
class Store : public Instruction
{
public:

	Store(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class Move : public Instruction
{
public:

	Move(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

