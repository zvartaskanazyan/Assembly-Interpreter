#include "arithmetic_logic_unit.h"
#include "exception.h"
#include "cpu.h"
#include <iostream>
#include <string>
#include <vector>

//Arithmetic operations
Add::Add(CPU* c, const Token& token) :Instruction(c, token)
{
}

void Add::check_params(const Token& token)  
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}

void Add::execute()
{
	check_params(token);
	statusFlag.OF = isAddOverflow(token);
	statusFlag.CF = isAddCarry(token);

	if (token.offset == "b")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int8_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int8_t));
		for (size_t index = 0; index < sizeof(int8_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) + computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "w")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int16_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int16_t));
		for (size_t index = 0; index < sizeof(int16_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) + computer->getRegisterValue(temp1[index]));
		}
	}

	else if (token.offset == "dw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int32_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int32_t));
		for (size_t index = 0; index < sizeof(int32_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) + computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "qw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int64_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int64_t));
		for (size_t index = 0; index < sizeof(int64_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) + computer->getRegisterValue(temp1[index]));
		}
	}
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}

Adc::Adc(CPU* c, const Token& token) :Instruction(c, token)
{
}

void Adc::check_params(const Token& token) 
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}

void Adc::execute()
{
	check_params(token) ;
	statusFlag.OF = isAddOverflow(token);
	statusFlag.CF = isAddCarry(token);
	if (token.offset == "b")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int8_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int8_t));
		for (size_t index = 0; index < sizeof(int8_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) + computer->getRegisterValue(temp1[index]) + getCarryFlag());
		}
	}
	else if (token.offset == "w")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int16_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int16_t));
		for (size_t index = 0; index < sizeof(int16_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) + computer->getRegisterValue(temp1[index]) + getCarryFlag());
		}
	}

	else if (token.offset == "dw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int32_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int32_t));
		for (size_t index = 0; index < sizeof(int32_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) + computer->getRegisterValue(temp1[index]) + getCarryFlag());
		}
	}
	else if (token.offset == "qw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int64_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int64_t));
		for (size_t index = 0; index < sizeof(int64_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) + computer->getRegisterValue(temp1[index]) + getCarryFlag());
		}
	}
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}

Sub::Sub(CPU* c, const Token& token) :Instruction(c, token)
{
}

void Sub::check_params(const Token& token) 
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}

void Sub::execute()
{
	check_params(token) ;
	statusFlag.OF = isSubOverflow(token);
	statusFlag.CF = isSubCarry(token);
	if (token.offset == "b")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int8_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int8_t));
		for (size_t index = 0; index < sizeof(int8_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) - computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "w")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int16_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int16_t));
		for (size_t index = 0; index < sizeof(int16_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) - computer->getRegisterValue(temp1[index]));
		}
	}

	else if (token.offset == "dw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int32_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int32_t));
		for (size_t index = 0; index < sizeof(int32_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) - computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "qw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int64_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int64_t));
		for (size_t index = 0; index < sizeof(int64_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) - computer->getRegisterValue(temp1[index]));
		}
	}
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}

Sbb::Sbb(CPU* c, const Token& token) :Instruction(c, token)
{

}
void Sbb::check_params(const Token& token) 
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}
void Sbb::execute()
{
	check_params(token) ;
	statusFlag.OF = isSubOverflow(token);
	statusFlag.CF = isSubCarry(token);
	if (token.offset == "b")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int8_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int8_t));
		for (size_t index = 0; index < sizeof(int8_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) - computer->getRegisterValue(temp1[index]) - getCarryFlag());
		}
	}
	else if (token.offset == "w")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int16_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int16_t));
		for (size_t index = 0; index < sizeof(int16_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) - computer->getRegisterValue(temp1[index]) - getCarryFlag());
		}
	}

	else if (token.offset == "dw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int32_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int32_t));
		for (size_t index = 0; index < sizeof(int32_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) - computer->getRegisterValue(temp1[index]) - getCarryFlag());
		}
	}
	else if (token.offset == "qw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int64_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int64_t));
		for (size_t index = 0; index < sizeof(int64_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) - computer->getRegisterValue(temp1[index]) - getCarryFlag());
		}
	}
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}

Mul::Mul(CPU* c, const Token& token) :Instruction(c, token)
{
}

void Mul::check_params(const Token& token) 
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}

void Mul::execute()
{
	check_params(token) ;
	statusFlag.OF = false;
	statusFlag.CF = isMulCarry(token);
	if (token.offset == "b")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int8_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int8_t));
		for (size_t index = 0; index < sizeof(int8_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) * computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "w")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int16_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int16_t));
		for (size_t index = 0; index < sizeof(int16_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) * computer->getRegisterValue(temp1[index]));
		}
	}

	else if (token.offset == "dw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int32_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int32_t));
		for (size_t index = 0; index < sizeof(int32_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) * computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "qw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int64_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int64_t));
		for (size_t index = 0; index < sizeof(int64_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) * computer->getRegisterValue(temp1[index]));
		}
	}
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}

IMul::IMul(CPU* c, const Token& token) :Instruction(c, token)
{
}

void IMul::check_params(const Token& token) 
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}

void IMul::execute()
{
	check_params(token) ;
	statusFlag.OF = isIMulOverflow(token);
	statusFlag.CF = false;
	if (token.offset == "b")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int8_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int8_t));
		for (size_t index = 0; index < sizeof(int8_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) * computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "w")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int16_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int16_t));
		for (size_t index = 0; index < sizeof(int16_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) * computer->getRegisterValue(temp1[index]));
		}
	}

	else if (token.offset == "dw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int32_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int32_t));
		for (size_t index = 0; index < sizeof(int32_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) * computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "qw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int64_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int64_t));
		for (size_t index = 0; index < sizeof(int64_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) * computer->getRegisterValue(temp1[index]));
		}
	}
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}


Div::Div(CPU* c, const Token& token) :Instruction(c, token)
{
}

void Div::check_params(const Token& token) 
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}

void Div::execute()
{
	check_params(token) ;
	if (computer->getRegisterValue(token.second) == 0)
		throw  Division_by_Zero();

	statusFlag.OF = false;
	statusFlag.CF = isDivCarry(token);
	if (token.offset == "b")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int8_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int8_t));
		for (size_t index = 0; index < sizeof(int8_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) / computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "w")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int16_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int16_t));
		for (size_t index = 0; index < sizeof(int16_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) / computer->getRegisterValue(temp1[index]));
		}
	}

	else if (token.offset == "dw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int32_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int32_t));
		for (size_t index = 0; index < sizeof(int32_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) / computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "qw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int64_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int64_t));
		for (size_t index = 0; index < sizeof(int64_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) / computer->getRegisterValue(temp1[index]));
		}
	}
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}

IDiv::IDiv(CPU* c, const Token& token) :Instruction(c, token)
{
}

void IDiv::check_params(const Token& token) 
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}

void IDiv::execute()
{
	check_params(token) ;
	if (computer->getRegisterValue(token.second) == 0)
		throw  Division_by_Zero();
	statusFlag.OF = isIDivOverflow(token);
	statusFlag.CF = false;
	if (token.offset == "b")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int8_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int8_t));
		for (size_t index = 0; index < sizeof(int8_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) / computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "w")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int16_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int16_t));
		for (size_t index = 0; index < sizeof(int16_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) / computer->getRegisterValue(temp1[index]));
		}
	}

	else if (token.offset == "dw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int32_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int32_t));
		for (size_t index = 0; index < sizeof(int32_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) / computer->getRegisterValue(temp1[index]));
		}
	}
	else if (token.offset == "qw")
	{
		std::vector<std::string> temp1 = computer->getRegs(Conditions::regIndex(token.second), Conditions::regIndex(token.second) + sizeof(int64_t));
		std::vector<std::string> temp = computer->getRegs(Conditions::regIndex(token.first), Conditions::regIndex(token.first) + sizeof(int64_t));
		for (size_t index = 0; index < sizeof(int64_t); ++index)
		{
			computer->setRegisterValue(temp[index], computer->getRegisterValue(temp[index]) / computer->getRegisterValue(temp1[index]));
		}
	}
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}

Increment::Increment(CPU* c, const Token& token) : Instruction(c, token)
{
}

void Increment::check_params(const Token& token) 
{
	if (token.first == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
}

void Increment::execute()
{
	check_params(token) ;
	computer->setRegisterValue(token.first, computer->getRegisterValue(token.first) + 1);
	statusFlag.OF = isIncOverflow(token);
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}

Decrement::Decrement(CPU* c, const Token& token) : Instruction(c, token)
{
}
void Decrement::check_params(const Token& token) 
{
	if (token.first == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
}
void Decrement::execute()
{
	check_params(token) ;
	computer->setRegisterValue(token.first, computer->getRegisterValue(token.first) - 1);
	statusFlag.OF = isDecOverflow(token);
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}

//Bitwise operations
And::And(CPU* c, const Token& token) : Instruction(c, token)
{
}

void And::check_params(const Token& token) 
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}

void And::execute()
{
	check_params(token) ;
	statusFlag.OF = false;
	statusFlag.CF = false;
	computer->setRegisterValue(token.first, computer->getRegisterValue(token.first) & computer->getRegisterValue(token.second));
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}

Or::Or(CPU* c, const Token& token) : Instruction(c, token)
{
}

void Or::check_params(const Token& token) 
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}

void Or::execute()
{
	check_params(token) ;
	statusFlag.OF = false;
	statusFlag.CF = false;
	computer->setRegisterValue(token.first, computer->getRegisterValue(token.first) | computer->getRegisterValue(token.second));
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}

Xor::Xor(CPU* c, const Token& token) : Instruction(c, token)
{
}

void Xor::check_params(const Token& token) 
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}

void Xor::execute()
{
	check_params(token) ;
	statusFlag.OF = false;
	statusFlag.CF = false;
	computer->setRegisterValue(token.first, computer->getRegisterValue(token.first) ^ computer->getRegisterValue(token.second));
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}

Not::Not(CPU* c, const Token& token) : Instruction(c, token)
{
}

void Not::check_params(const Token& token) 
{
	if (token.first == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
}

void Not::execute()
{
	check_params(token) ;
	computer->setRegisterValue(token.first, ~(computer->getRegisterValue(token.first)));
}

ShiftLeft::ShiftLeft(CPU* c, const Token& token) : Instruction(c, token)
{
}

void ShiftLeft::check_params(const Token& token) 
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
}

void ShiftLeft::execute()
{
	check_params(token) ;
	if (computer->getRegisterValue(token.first) < 0 && computer->getRegisterValue(token.second) < 0)
		throw Cant_be_Shifted();
	if (computer->getRegisterValue(token.second) > sizeof(int))
		throw Out_of_Range();
	computer->setRegisterValue(token.first, (computer->getRegisterValue(token.first) << std::stoi(token.second)));
}

ShiftRight::ShiftRight(CPU* c, const Token& token) : Instruction(c, token)
{
}

void ShiftRight::check_params(const Token& token) 
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
}
void ShiftRight::execute()
{
	check_params(token) ;
	if (computer->getRegisterValue(token.first) < 0 && computer->getRegisterValue(token.second) < 0)
		throw Cant_be_Shifted();
	if (computer->getRegisterValue(token.second) > sizeof(int))
		throw Out_of_Range();
	computer->setRegisterValue(token.first, (computer->getRegisterValue(token.first) >> std::stoi(token.second)));
}

Test::Test(CPU* c, const Token& token) : Instruction(c, token)
{
}

void Test::check_params(const Token& token)
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}

void Test::execute()
{
	check_params(token);
	statusFlag.OF = false;
	statusFlag.CF = false;
	unsigned temp = computer->getRegisterValue(token.first) - computer->getRegisterValue(token.second);
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}

Compare::Compare(CPU* c, const Token& token) : Instruction(c, token)
{
}

void Compare::check_params(const Token& token) 
{
	if (token.second == "")
		throw Wrong_Parameters();
	if (!Conditions::isRegister(token.first))
		throw Invalid_First_Register();
	if (!Conditions::isRegister(token.second))
		throw Invalid_Second_Register();
}

void Compare::execute()
{
	check_params(token) ;
	statusFlag.OF = isSubOverflow(token);
	statusFlag.CF = isSubCarry(token);
	unsigned temp = (computer->getRegisterValue(token.first)) & (computer->getRegisterValue(token.second));
	statusFlag.ZF = (computer->getRegisterValue(token.first) == 0);
	statusFlag.SF = (computer->getRegisterValue(token.first) < 0);
}


End::End(CPU* c, const Token& token) :Instruction(c, token)
{

}

void End::check_params(const Token& token)  
{
	if (token.offset != "" && token.first != "" && token.second != "")
		throw Wrong_Parameters();
}

void End::execute() {
	check_params(token) ;
	computer->stopRunning();
}


