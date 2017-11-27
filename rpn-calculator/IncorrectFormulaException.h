#pragma once
#include <string>

using namespace std;

class IncorrectFormulaException : public exception
{
private:
	string message;

public:
	IncorrectFormulaException();
	IncorrectFormulaException(string message);
	~IncorrectFormulaException();

	string getMessage() const throw();
};

