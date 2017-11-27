#pragma once
#include <string>

using namespace std;

class CannotOpenFileException : public exception
{
private:
	string message;
public:
	CannotOpenFileException();
	CannotOpenFileException(string message);
	~CannotOpenFileException();

	string getMessage() const throw();
};