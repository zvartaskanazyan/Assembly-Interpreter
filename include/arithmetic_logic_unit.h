#pragma once
#include <string>
#include <vector>
#include "token.h"
#include "cpu.h"
#include "utility.h"
#include "instruction.h"


class Add : public Instruction
{
public:

	Add(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class Adc : public Instruction
{
public:

	Adc(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class Sub : public Instruction
{
public:

	Sub(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class Sbb : public Instruction
{
public:

	Sbb(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class Mul : public Instruction
{
public:

	Mul(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class IMul : public Instruction
{
public:

	IMul(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class Div : public Instruction
{
public:
	Div(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class IDiv : public Instruction
{
public:
	IDiv(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class Increment : public Instruction
{
public:

	Increment(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class Decrement : public Instruction
{
public:
	Decrement(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class And : public  Instruction

{
public:
	And(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class Or : public  Instruction
{
public:
	Or(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class Xor : public  Instruction
{
public:
	Xor(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class Not : public  Instruction
{
public:
	Not(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};


class ShiftRight : public  Instruction
{
public:
	ShiftRight(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class ShiftLeft : public  Instruction
{
public:
	ShiftLeft(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class Test : public  Instruction
{
public:
	Test(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class Compare : public  Instruction
{
public:
	Compare(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token) ;
};

class End : public Instruction {
public:

	End(CPU* c, const Token& token);
	void execute();
	void check_params(const Token& token);
};
