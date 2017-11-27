#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}

void MainMenu::startMainMenu()
{
	displayMainMenu();
	do
	{
		getOptionFromUser();
	} while ((option < 1) || (option > NUMBER_OF_MAIN_MENU_OPTIONS));
	handleOption();
}

int MainMenu::getOption()
{
	return option;
}

void MainMenu::displayMainMenu()
{
	cout << "1. Type formula with keyboard." << endl;
	cout << "2. Type RPN formula with keyboard." << endl;
	cout << "3. Load formulas from file." << endl;
	cout << "4. Load RPN formulas from file." << endl;
	cout << "5. Exit." << endl;
}

void MainMenu::getOptionFromUser()
{
	cout << "Choose option: ";
	while (!(cin >> option))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Incorrect input. Try again: ";
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
}

void MainMenu::handleOption()
{
	vector<Formula> formulas;
	Formula formula;
	FormulaMenu formulaMenu;
	switch (option)
	{
	case 1:
		formula = formulaMenu.getFormulaFromUser(false);
		formulas.push_back(formula);
		break;
	case 2:
		formula = formulaMenu.getFormulaFromUser(true);
		formulas.push_back(formula);
		break;
	case 3:
		try
		{
			formulas = formulaMenu.getFormulasFromFile(false);
		}
		catch (CannotOpenFileException cofe)
		{
			cout << cofe.getMessage();
		}
		break;
	case 4:
		try
		{
			formulas = formulaMenu.getFormulasFromFile(true);
		}
		catch (CannotOpenFileException cofe)
		{
			cout << cofe.getMessage();
		}
		break;
	case 5:
		exit(0);
		break;
	}
	Calculator calculator;
	calculator.handleFormulas(formulas);
	formulas.clear();
}