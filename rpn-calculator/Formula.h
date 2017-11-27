#pragma once
#include <string>
#include <stack>
#include "IncorrectFormulaException.h"

using namespace std;

class Formula
{
private:
	string formulaStr;
	string RPNFormula;
	bool isRPN;
	bool hasExpressionLowerPriority(char firstExpression, char secondExpression);
	bool isExpression(char sign);
	bool isBracket(char sign);
	bool isFormulaCorrect();

public:
	Formula();
	Formula(const Formula & formula);
	Formula(string formula, bool isRPN);
	~Formula();

	void convertToRPN();
	void setFormula(string formula);
	string getFormula();
	void setRPNFormula(string RPNFormula);
	string getRPNFormula();
	bool hasRPN();
	void setIsRPN(bool isRPN);
	bool isRPNFormulaValid();

	friend ostream & operator<<(ostream & out, const Formula & formula);
};