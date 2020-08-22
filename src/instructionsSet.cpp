#include "arithmetic_logic_unit.h"
#include "memory_instructions.h"
#include "conditional_jumps.h"
#include "instructionsSet.h"
#include "exception.h"
#include "utility.h"
#include "cpu.h"

Instruction* Instructions::CreateInstruction(CPU* c, const Token& token)
{
	if (Conditions::areEquals(token.command, "assign"))
		return new Assign(c, token);
	if (Conditions::areEquals(token.command, "store"))
		return new Store(c, token);
	if (Conditions::areEquals(token.command, "load"))
		return new Load(c, token);
	if (Conditions::areEquals(token.command, "move"))
		return new Move(c, token);
	if (Conditions::areEquals(token.command, "end"))
		return new End(c, token);
	if (Conditions::areEquals(token.command, "add"))
		return new Add(c, token);
	if (Conditions::areEquals(token.command, "adc"))
		return new Adc(c, token);
	if (Conditions::areEquals(token.command, "sub"))
		return new Sub(c, token);
	if (Conditions::areEquals(token.command, "sbb"))
		return new Sbb(c, token);
	if (Conditions::areEquals(token.command, "mul"))
		return new Mul(c, token);
	if (Conditions::areEquals(token.command, "imul"))
		return new IMul(c, token);
	if (Conditions::areEquals(token.command, "div"))
		return new Div(c, token);
	if (Conditions::areEquals(token.command, "idiv"))
		return new IDiv(c, token);
	if (Conditions::areEquals(token.command, "inc"))
		return new Increment(c, token);
	if (Conditions::areEquals(token.command, "dec"))
		return new Decrement(c, token);
	if (Conditions::areEquals(token.command, "and"))
		return new And(c, token);
	if (Conditions::areEquals(token.command, "or"))
		return new Or(c, token);
	if (Conditions::areEquals(token.command, "xor"))
		return new Xor(c, token);
	if (Conditions::areEquals(token.command, "not"))
		return new Not(c, token);
	if (Conditions::areEquals(token.command, "test"))
		return new Test(c, token);
	if (Conditions::areEquals(token.command, "cmp"))
		return new Compare(c, token);
	if (Conditions::areEquals(token.command, "shR"))
		return new ShiftRight(c, token);
	if (Conditions::areEquals(token.command, "shL"))
		return new ShiftLeft(c, token);
	if (Conditions::areEquals(token.command, "jump"))
		return new Jump(c, token);
	if (Conditions::areEquals(token.command, "jz"))
		return new JZ(c, token);
	if (Conditions::areEquals(token.command, "jnz"))
		return new JNZ(c, token);
	if (Conditions::areEquals(token.command, "jc"))
		return new JC(c, token);
	if (Conditions::areEquals(token.command, "jnc"))
		return new JNC(c, token);
	if (Conditions::areEquals(token.command, "js"))
		return new JS(c, token);
	if (Conditions::areEquals(token.command, "jns"))
		return new JNS(c, token);
	if (Conditions::areEquals(token.command, "ja"))
		return new JA(c, token);
	if (Conditions::areEquals(token.command, "jae"))
		return new JAE(c, token);
	if (Conditions::areEquals(token.command, "jb"))
		return new JB(c, token);
	if (Conditions::areEquals(token.command, "jbe"))
		return new JBE(c, token);
	if (Conditions::areEquals(token.command, "jg"))
		return new JG(c, token);
	if (Conditions::areEquals(token.command, "jge"))
		return new JGE(c, token);
	if (Conditions::areEquals(token.command, "jo"))
		return new JO(c, token);
	if (Conditions::areEquals(token.command, "jno"))
		return new JNO(c, token);
	throw Wrong_Instruction();
}

