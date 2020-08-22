#include "conditional_jumps.h"
#include "exception.h"
#include "cpu.h"

Jump::Jump(CPU* c, const Token& token) :Instruction(c, token)
{

}
void Jump::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}

void Jump::execute()
{
	check_params(token);
	computer->updatePC(token.first);
}

JZ::JZ(CPU* c, const Token& token) : Instruction(c, token)
{

}
void JZ::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JZ::execute()
{
	check_params(token);
	if (statusFlag.ZF == true)
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}

JNZ::JNZ(CPU* c, const Token& token) : Instruction(c, token)
{

}
void JNZ::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JNZ::execute()
{
	check_params(token);
	if (statusFlag.ZF == false)
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}

JC::JC(CPU* c, const Token& token) : Instruction(c, token)
{

}
void JC::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JC::execute()
{
	check_params(token);
	if (statusFlag.CF == true)
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}

JNC::JNC(CPU* c, const Token& token) : Instruction(c, token)
{
}

void JNC::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JNC::execute()
{
	check_params(token);
	if (statusFlag.CF == false)
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}

JS::JS(CPU* c, const Token& token) : Instruction(c, token)
{
}

void JS::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}

void JS::execute()
{
	check_params(token);
	if (statusFlag.SF == true)
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}

JNS::JNS(CPU* c, const Token& token) : Instruction(c, token)
{

}
void JNS::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JNS::execute()
{
	check_params(token);
	if (statusFlag.CF == false)
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}

JA::JA(CPU* c, const Token& token) : Instruction(c, token)
{

}
void JA::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JA::execute()
{
	check_params(token);
	if ((statusFlag.CF == false) & (statusFlag.ZF == false))
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}

JAE::JAE(CPU* c, const Token& token) : Instruction(c, token)
{

}
void JAE::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JAE::execute()
{
	check_params(token);
	if (statusFlag.CF == false)
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}

JB::JB(CPU* c, const Token& token) : Instruction(c, token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JB::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JB::execute()
{
	check_params(token);
	if (statusFlag.CF == true)
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}

JBE::JBE(CPU* c, const Token& token) : Instruction(c, token)
{

}
void JBE::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JBE::execute()
{
	check_params(token);
	if ((statusFlag.CF == true) | (statusFlag.ZF == true))
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}

JG::JG(CPU* c, const Token& token) : Instruction(c, token)
{

}
void JG::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JG::execute()
{
	check_params(token);
	if ((statusFlag.ZF == false) & (statusFlag.SF == statusFlag.OF))
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}

JGE::JGE(CPU* c, const Token& token) : Instruction(c, token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JGE::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JGE::execute()
{
	check_params(token);
	if (statusFlag.SF == statusFlag.OF)
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}

JO::JO(CPU* c, const Token& token) : Instruction(c, token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JO::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JO::execute()
{
	check_params(token);
	if (statusFlag.OF == true)
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}

JNO::JNO(CPU* c, const Token& token) : Instruction(c, token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JNO::check_params(const Token& token)
{
	if (token.second != "")
		throw Wrong_Parameters();
}
void JNO::execute()
{
	check_params(token);
	if (statusFlag.OF == false)
	{
		computer->updatePC(token.first);
	}
	else
	{
		computer->incrementPC();
	}
}