#pragma once
#include "Formula.h"
#include "ResultView.h"
#include <stack>
#include <vector>
class Calculator
{
public:
	Calculator();
	~Calculator();
	double calculate(Formula & formula);
	void handleFormulas(vector<Formula> formulas);
};

