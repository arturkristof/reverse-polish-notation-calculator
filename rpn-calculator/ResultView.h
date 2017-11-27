#pragma once
#include "Formula.h"
#include <iostream>

using namespace std;

class ResultView
{
public:
	ResultView();
	~ResultView();
	void displayResult(Formula formula, double result);
};

