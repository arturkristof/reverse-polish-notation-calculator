#include "CannotOpenFileException.h"



CannotOpenFileException::CannotOpenFileException()
{
}

CannotOpenFileException::CannotOpenFileException(string message)
{
	this->message = message + "\n";
}

CannotOpenFileException::~CannotOpenFileException()
{
}

string CannotOpenFileException::getMessage() const throw()
{
	return message;
}
