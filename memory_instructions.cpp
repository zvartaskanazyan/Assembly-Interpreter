#include "exception.h"
#include "memory_instructions.h"
#include "utility.h"
#include "cpu.h"
#include "token.h"

Assign::Assign(CPU* c, const Token& token) :Instruction(c, token)
{

}
void Assign::check_params(const Token& token)
{
	if (token.second == "")
		throw  Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
}
void Assign::execute()
{
	check_params(token);
	if (token.offset == "b")
	{
		union {
			int value;
			unsigned char byte[sizeof(int8_t)];
		} regs;

		regs.value = std::stoi(token.second);
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int8_t));
		for (size_t index = 0; index < sizeof(int8_t); ++index)
		{
			computer->setRegisterValue(temp[index], regs.byte[index]);
		}
	}
	else if (token.offset == "w")
	{
		union {
			int value;
			unsigned char byte[sizeof(int16_t)];
		}regs;

		regs.value = std::stoi(token.second);
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int16_t));
		for (size_t index = 0; index < sizeof(int16_t); ++index)
		{
			computer->setRegisterValue(temp[index], regs.byte[index]);
		}
	}

	else if (token.offset == "dw")
	{
		union {
			int value;
			unsigned char byte[sizeof(int32_t)];
		}regs;

		regs.value = std::stoi(token.second);
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int32_t));
		for (size_t index = 0; index < sizeof(int32_t); ++index)
		{
			computer->setRegisterValue(temp[index], regs.byte[index]);
		}
	}
	else if (token.offset == "qw")
	{
		union {
			int value;
			unsigned char byte[sizeof(int64_t)];
		} regs;

		regs.value = std::stoi(token.second);
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int64_t));
		for (size_t index = 0; index < sizeof(int64_t); ++index)
		{
			computer->setRegisterValue(temp[index], regs.byte[index]);
		}
	}
	computer->incrementPC();
}

Load::Load(CPU* c, const Token& token) :Instruction(c, token)
{
	
}
void Load::check_params(const Token& token)
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_First_Register();
}
void Load::execute()
{
	check_params(token);
	if (token.offset == "b")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int8_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int8_t));
		for (size_t index = 0; index < sizeof(int8_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "w")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int16_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int16_t));
		for (size_t index = 0; index < sizeof(int16_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp1[index]));
		}
	}

	else if (token.offset == "dw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int32_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int32_t));
		for (size_t index = 0; index < sizeof(int32_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "qw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int64_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int64_t));
		for (size_t index = 0; index < sizeof(int64_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp1[index]));
		}
	}
	computer->incrementPC();
}

Move::Move(CPU* c, const Token& token) :Instruction(c, token)
{

}

void Move::check_params(const Token& token)
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
}

void Move::execute()
{
	check_params(token);
	if (token.offset == "b")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int8_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int8_t));
		for (size_t index = 0; index < sizeof(int8_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "w")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int16_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int16_t));
		for (size_t index = 0; index < sizeof(int16_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp1[index]));
		}
	}

	else if (token.offset == "dw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int32_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int32_t));
		for (size_t index = 0; index < sizeof(int32_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "qw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int64_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int64_t));
		for (size_t index = 0; index < sizeof(int64_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp1[index]));
		}
	}
	computer->incrementPC();
}

Store::Store(CPU* c, const Token& token) :Instruction(c, token)
{

}

void Store::check_params(const Token& token)
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}

void Store::execute()
{
	check_params(token);
	if (token.offset == "b")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int8_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int8_t));
		for (size_t index = 0; index < sizeof(int8_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "w")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int16_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int16_t));
		for (size_t index = 0; index < sizeof(int16_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp1[index]));
		}
	}

	else if (token.offset == "dw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int32_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int32_t));
		for (size_t index = 0; index < sizeof(int32_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "qw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int64_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int64_t));
		for (size_t index = 0; index < sizeof(int64_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp1[index]));
		}
	}
	computer->incrementPC();
}
