#include "FormulaMenu.h"

FormulaMenu::FormulaMenu()
{
}


FormulaMenu::~FormulaMenu()
{
}

Formula FormulaMenu::getFormulaFromUser(bool isRPN)
{
	string formulaFromUser;
	cout << "Type formula: ";
	getline(cin, formulaFromUser);
	Formula formula(formulaFromUser, isRPN);
	return formula;
}

vector<Formula> FormulaMenu::getFormulasFromFile(bool isRPN)
{
	vector<Formula> formulasFromFile;
	string fileName;
	cout << "Type file name: ";
	getline(cin, fileName);

	string formulaFromFile;
	ifstream file(fileName);
	if (file.is_open())
	{
		while (getline(file, formulaFromFile))
		{
			Formula formula(formulaFromFile, isRPN);
			formulasFromFile.push_back(formula);
		}
		file.close();
	}
	else
	{
		CannotOpenFileException cannotOpenFileException("Unable to open file.");
		throw cannotOpenFileException;
	}
	return formulasFromFile;
}