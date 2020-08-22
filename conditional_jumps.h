#pragma once
#include "arithmetic_logic_unit.h"
#include "instruction.h"


class Jump : public  Instruction
{
public:
	Jump(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JZ : public Instruction
{
public:
	JZ(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JNZ : public Instruction
{
public:

	JNZ(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JC : public Instruction
{
public:

	JC(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JNC : public Instruction
{
public:
	JNC(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JS : public Instruction
{
public:

	JS(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JNS : public Instruction
{
public:

	JNS(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JA : public Instruction
{
public:

	JA(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JAE : public Instruction
{
public:

	JAE(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JB : public Instruction
{
public:

	JB(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JBE : public Instruction
{
public:

	JBE(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JG : public Instruction
{
public:

	JG(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JGE : public Instruction
{
public:

	JGE(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JO : public Instruction
{
public:

	JO(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};

class JNO : public Instruction
{
public:

	JNO(CPU* c, const Token& token);
	void check_params(const Token& token);
	void execute();
};