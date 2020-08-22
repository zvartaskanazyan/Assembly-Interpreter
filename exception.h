#pragma once
#include <exception>

class Exeption : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Exeption!";
	}
	virtual ~Exeption() {}
};

class Wrong_Parameters : public Exeption
{
public:
	const char* what() const throw()
	{
		return "Wrong numbers of parameters!!";
	}
};

class Invalid_First_Register : public Exeption
{
public:
	const char* what() const throw()
	{
		return "The first parameter  doesn't seem a valid register!!";
	}
};

class Invalid_Second_Register : public Exeption
{
public:
	const char* what() const throw()
	{
		return "The second parameter  doesn't seem a valid register!!";
	}
};

class Wrong_Instruction : public Exeption
{
public:
	const char* what() const throw()
	{
		return "Instruction not found!!";
	}
};

class Wrong_Filename : public Exeption
{
public:
	const char* what() const throw()
	{
		return "File not found!!";
	}
};

class Cant_be_Shifted : public Exeption
{
public:
	const char* what() const throw()
	{
		return "The negative number can't be shefted!!";
	}
};

class Out_of_Range : public Exeption
{
public:
	const char* what() const throw()
	{
		return "The  number is shifted more than the size of integer!!";
	}
};

class File_Doesnt_Open : public Exeption
{
public:
	const char* what() const throw()
	{
		return "The file can't be open!!";
	}

};

class Lable_Not_Found : public Exeption
{
public:
	const char* what() const throw()
	{
		return "The lable not found!!";
	}

};

class Division_by_Zero : public Exeption
{
public:
	const char* what() const throw()
	{
		return "The division by zero is undefind behavior!!";
	}

};