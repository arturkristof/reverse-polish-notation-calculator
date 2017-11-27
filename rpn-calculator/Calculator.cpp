#include "Calculator.h"

Calculator::Calculator()
{
}


Calculator::~Calculator()
{
}

void Calculator::handleFormulas(vector<Formula> formulas)
{
	double result;
	ResultView resultView;
	for (auto &currentFormula : formulas)
	{
		try
		{
			result = calculate(currentFormula);
			resultView.displayResult(currentFormula, result);
		}
		catch (IncorrectFormulaException ife)
		{
			cout << ife.getMessage();
		}
	}
}

double Calculator::calculate(Formula & formula)
{
	if (!(formula.hasRPN()))
	{
		formula.convertToRPN();
	}
	string RPNFormula = formula.getRPNFormula();
	string tmp;
	double firstNumber;
	double secondNumber;
	double result;
	if (formula.isRPNFormulaValid())
	{
		stack<string> stackForCalculating;
		for (size_t i = 0; i < RPNFormula.size(); ++i)
		{
			tmp = "";
			if (isdigit(RPNFormula[i]))
			{
				while (isdigit(RPNFormula[i]) || RPNFormula[i] == '.')
				{
					tmp += RPNFormula[i];
					i++;
				}
				i--;
				stackForCalculating.push(tmp);
			}
			else if (RPNFormula[i] != ' ')
			{
				firstNumber = atof(stackForCalculating.top().c_str());
				stackForCalculating.pop();
				secondNumber = atof(stackForCalculating.top().c_str());
				stackForCalculating.pop();
				switch (RPNFormula[i])
				{
				case '+':
					result = secondNumber + firstNumber;
					break;
				case '-':
					result = secondNumber - firstNumber;
					break;
				case '*':
					result = secondNumber * firstNumber;
					break;
				case '/':
					result = secondNumber / firstNumber;
					break;
				case '^':
					result = pow(secondNumber, firstNumber);
					break;
				default:
					break;
				}
				stackForCalculating.push(to_string(result));
			}
		}
		result = atof(stackForCalculating.top().c_str());
		return result;
	}
	else
	{
		IncorrectFormulaException incorrectFormulaException("Incorrect RPN formula.");
		throw incorrectFormulaException;
	}
}