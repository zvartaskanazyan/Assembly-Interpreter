#pragma once
#include <iostream>
#include "exception.h"
#include "token.h"
#include "cpu.h"

struct Status_Flags
{
	bool ZF = false;
	bool CF = false;
	bool SF = false;
	bool OF = false;
};

class Instruction {
public:

	Instruction(CPU* c, const Token& vec) : computer(c), token(vec) {}
	virtual void execute() = 0;
	virtual void check_params(const Token& token) = 0;
	virtual ~Instruction() {}

protected:
	Token token;
	CPU* computer;
	Status_Flags statusFlag;

	//for signed arithmetic
	bool isAddOverflow(const Token& token) const
	{
		return (computer->getRegisterValue(token.first) + computer->getRegisterValue(token.second) > std::numeric_limits<int>::max()
			|| computer->getRegisterValue(token.first) + computer->getRegisterValue(token.second) < std::numeric_limits<int>::min()
			|| (computer->getRegisterValue(token.first) < 0 && computer->getRegisterValue(token.second) < 0
				&& computer->getRegisterValue(token.first) + computer->getRegisterValue(token.second) > 0));
	}

	//for unsigned arithmetic
	bool isAddCarry(const Token& token) const
	{
		return ((computer->getRegisterValue(token.first) + computer->getRegisterValue(token.second)) > std::numeric_limits<int>::max()
			|| (computer->getRegisterValue(token.first) > 0 && computer->getRegisterValue(token.second) > 0)
			&& ((computer->getRegisterValue(token.first) + computer->getRegisterValue(token.first)) < 0));
	}

	bool isSubOverflow(const Token& token) const
	{
		return ((computer->getRegisterValue(token.first) > 0 && computer->getRegisterValue(token.second) < 0
			&& computer->getRegisterValue(token.first) - computer->getRegisterValue(token.second) < 0)
			|| (computer->getRegisterValue(token.first) < 0 && computer->getRegisterValue(token.second) > 0
				&& computer->getRegisterValue(token.first) - computer->getRegisterValue(token.second) > 0));

	}

	bool isSubCarry(const Token& expr) const
	{
		return ((computer->getRegisterValue(token.first) > 0 && computer->getRegisterValue(token.second) > 0)
			&& (computer->getRegisterValue(token.second) > computer->getRegisterValue(token.first))); // borrow
	}

	bool isMulCarry(const Token& token) const
	{
		return ((computer->getRegisterValue(token.first) > 0 && computer->getRegisterValue(token.second) > 0)
			&& computer->getRegisterValue(token.first) * computer->getRegisterValue(token.second) > std::numeric_limits<int>::max());
	}

	bool isIMulOverflow(const Token& token) const
	{
		return (computer->getRegisterValue(token.first) * computer->getRegisterValue(token.second) > std::numeric_limits<int>::max()
			|| computer->getRegisterValue(token.first) * computer->getRegisterValue(token.second) < std::numeric_limits<int>::min());
	}

	bool isIDivOverflow(const Token& expr) const
	{
		return (computer->getRegisterValue(token.first) / computer->getRegisterValue(token.second) > std::numeric_limits<int>::max());
	}

	bool isDivCarry(const Token& expr) const
	{
		return ((computer->getRegisterValue(token.first) > 0 && computer->getRegisterValue(token.second) > 0) &&
			computer->getRegisterValue(token.first) / computer->getRegisterValue(token.second) > std::numeric_limits<int>::max());
	}
	bool isIncOverflow(const Token& expr) const
	{
		return (computer->getRegisterValue(token.first) > std::numeric_limits<int>::max());
	}

	bool isDecOverflow(const Token& expr) const
	{
		return (computer->getRegisterValue(token.first) < std::numeric_limits<int>::min());
	}

	int getCarryFlag() const { return int(statusFlag.CF); }
};



