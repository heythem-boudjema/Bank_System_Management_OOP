
#include <iostream>
#include "clsInputValidate.h"
using namespace std;
int main()
{
	cout << clsInputValidate::IsNumberBetween(5, 1, 6);
	cout << "Please Enter A number" << endl;

	cout << clsInputValidate::ReadDblNumber("Invalid NUmber, Enter Again");
	cout << clsInputValidate::IsValidDate(clsDate("41/2/2022"));
	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(27, 01, 2024), clsDate(29, 01, 2026));
	cout << "Please Enter A number" << endl;

	cout << clsInputValidate::ReadIntNumberBetween(14, 25, "Invalid Number A bb");


}

