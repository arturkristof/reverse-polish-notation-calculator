#pragma once
#include "FormulaMenu.h"
#include "Formula.h"
#include "Calculator.h"
#include <iostream>
#include <vector>

class MainMenu
{
private:
	const int NUMBER_OF_MAIN_MENU_OPTIONS = 5;
	int option;

	void displayMainMenu();
	void getOptionFromUser();
	void handleOption();

public:
	MainMenu();
	~MainMenu();

	void startMainMenu();
	
	int getOption();
};