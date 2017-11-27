#include "IncorrectFormulaException.h"



IncorrectFormulaException::IncorrectFormulaException()
{
}

IncorrectFormulaException::IncorrectFormulaException(string message)
{
	this->message = message + "\n";
}


IncorrectFormulaException::~IncorrectFormulaException()
{
}

string IncorrectFormulaException::getMessage() const throw()
{
	return message;
}
