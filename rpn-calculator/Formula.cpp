#include "Formula.h"

Formula::Formula()
{
	this->formulaStr = "";
	this->RPNFormula = "";
	this->isRPN = false;
}

Formula::Formula(const Formula & formula)
{
	formulaStr = formula.formulaStr;
	RPNFormula = formula.RPNFormula;
	isRPN = formula.isRPN;
}

Formula::Formula(string formula, bool isRPN)
{
	if (isRPN)
	{
		this->RPNFormula = formula;
	}
	else
	{
		this->formulaStr = formula;
	}
	this->isRPN = isRPN;
}

Formula::~Formula()
{
}

string Formula::getFormula()
{
	return this->formulaStr;
}

void Formula::setRPNFormula(string RPNFormula)
{
	this->RPNFormula = RPNFormula;
}

string Formula::getRPNFormula()
{
	return this->RPNFormula;
}

bool Formula::hasRPN()
{
	return this->isRPN;
}

void Formula::setIsRPN(bool isRPN)
{
	this->isRPN = isRPN;
}

bool Formula::isRPNFormulaValid()
{
	if (RPNFormula == "")
	{
		return false;
	}

	if (isExpression(RPNFormula[0]))
	{
		return false;
	}

	int numbersCounter = 0;
	int expressionsCounter = 0;
	for (size_t i = 0; i < RPNFormula.size(); ++i)
	{
		if (isdigit(RPNFormula[i]))
		{
			while ((isdigit(RPNFormula[i])) || RPNFormula[i] == '.')
			{
				i++;
			}
			i--;
			numbersCounter++;
		}
		else if (isExpression(RPNFormula[i]))
		{
			expressionsCounter++;
		}
		else if(RPNFormula[i] != ' ')
		{
			return false;
		}
		if (numbersCounter == expressionsCounter)
		{
			return false;
		}
	}

	if (numbersCounter == (expressionsCounter + 1))
	{
		return true;
	}
	
	return false;
}

void Formula::convertToRPN()
{
	if (isFormulaCorrect())
	{
		stack<char> stackForConverting;
		for (size_t i = 0; i < formulaStr.size(); ++i)
		{
			if (isdigit(formulaStr[i]))
			{
				while ((isdigit(formulaStr[i])) || formulaStr[i] == '.')
				{
					this->RPNFormula += formulaStr[i];
					i++;
				}
				i--;
				this->RPNFormula += " ";
			}
			else if(isExpression(formulaStr[i]) || isBracket(formulaStr[i]))
			{
				if (stackForConverting.empty())
				{
					stackForConverting.push(formulaStr[i]);
				}
				else
				{
					char newExpression = formulaStr[i];
					char lastExpression = stackForConverting.top();

					if (newExpression == '(')
					{
						stackForConverting.push(newExpression);
					}
					else if (newExpression == ')')
					{
						this->RPNFormula += lastExpression;
						stackForConverting.pop();
						do
						{
							newExpression = stackForConverting.top();
							stackForConverting.pop();
							if (newExpression != '(')
							{
								this->RPNFormula += " ";
								this->RPNFormula += newExpression;
							}
						} while (newExpression != '(');
						this->RPNFormula += " ";
					}
					else if (hasExpressionLowerPriority(newExpression, lastExpression))
					{
						this->RPNFormula += lastExpression;
						this->RPNFormula += " ";
						stackForConverting.pop();
						stackForConverting.push(newExpression);
					}
					else
					{
						stackForConverting.push(newExpression);
					}
				}
			}
		}

		while (stackForConverting.size() > 0)
		{
			this->RPNFormula += stackForConverting.top();
			this->RPNFormula += " ";
			stackForConverting.pop();
		}
	}
	else
	{
		IncorrectFormulaException incorrectFormulaException("Formula is not correct.");
		throw incorrectFormulaException;
	}
}

bool Formula::hasExpressionLowerPriority(char firstExpression, char secondExpression)
{
	switch (firstExpression)
	{
	case '+':
	case '-':
		return ((secondExpression == '*')
			|| (secondExpression == '/')
			|| (secondExpression == '^'));
		break;
	case '*':
	case '/':
		return (secondExpression == '^');
		break;
	default:
		return false;
		break;
	}
}

bool Formula::isFormulaCorrect()
{
	if (formulaStr == "")
	{
		return false;
	}

	int lastIndexOfFormula = formulaStr.size() - 1;
	if (isExpression(formulaStr[0]) || isExpression(formulaStr[lastIndexOfFormula]))
	{
		return false;
	}

	int numbersCounter = 0;
	int expressionsCounter = 0;
	int rigthBracketsCounter = 0;
	int leftBracketsCounter = 0;
	for (size_t i = 0; i < formulaStr.size(); ++i)
	{
		if (isdigit(formulaStr[i]))
		{
			while ((isdigit(formulaStr[i])) || formulaStr[i] == '.')
			{
				if (formulaStr[i] == '.')
				{
					if (i == lastIndexOfFormula)
					{
						return false;
					}
					
					if (!isdigit(formulaStr[i + 1]))
					{
						return false;
					}
				}
				i++;
			}
			i--;
			numbersCounter++;
		}
		else if (isExpression(formulaStr[i]))
		{
				expressionsCounter++;
		}
		else if (formulaStr[i] == '(')
		{
			leftBracketsCounter++;
		}
		else if (formulaStr[i] == ')')
		{
			rigthBracketsCounter++;
		}
		else if (formulaStr[i] != ' ')
		{
			return false;
		}
	}

	if (leftBracketsCounter != rigthBracketsCounter)
	{
		return false;
	}

	if (numbersCounter != (expressionsCounter + 1))
	{
		return false;
	}

	return true;
}

bool Formula::isExpression(char sign)
{
	switch (sign)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
		return true;
		break;
	default:
		return false;
		break;
	}
}

bool Formula::isBracket(char sign)
{
	switch (sign)
	{
	case '(':
	case ')':
		return true;
		break;
	default:
		return false;
		break;
	}
}

void Formula::setFormula(string formula)
{
	this->formulaStr = formula;
}

ostream & operator<<(ostream & out, const Formula & formula)
{
	return out << "Formula: " << formula.formulaStr << "\n"
		<< "RPN formula: " << formula.RPNFormula;
}
