#pragma once
#include "Formula.h"
#include "CannotOpenFileException.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class FormulaMenu
{
public:
	FormulaMenu();
	~FormulaMenu();
	Formula getFormulaFromUser(bool isRPN);
	vector<Formula> getFormulasFromFile(bool isRPN);
};

