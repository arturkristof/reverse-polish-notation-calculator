#include "ResultView.h"



ResultView::ResultView()
{
}


ResultView::~ResultView()
{
}

void ResultView::displayResult(Formula formula, double result)
{
	cout << formula << endl;
	cout << "Result: " << result << endl << endl;
}
