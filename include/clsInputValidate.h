#pragma once
#include <iostream>
#include "clsPeriod.h"
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;
class clsInputValidate
{


public :
    	template<typename T> static bool IsNumberBetween(T Num, T From, T To)
	{

		return (Num >= From and Num <= To);
	}


static	bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		if (clsDate::IsDate1AfterDate2(From, To))
			clsDate::SwapDates(From, To);

		clsPeriod P1(From, To);
		
		return P1.isDateInPeriod(Date);

	}
template <typename T>static T ReadNumber(string Message= "Invalid Number, Enter Again\n")
{
	T Num = 0;
	cin >> Num;
	while (cin.fail())
	{
		cout << "\033[91m";
		cout << Message << endl;
		cout << "\033[0m";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> Num;


	}
	return Num;
}
	
	template <typename T>static T ReadNumberBetween(T From, T To, string Message="Number Not Valid,Please Enter another one")
	{
		T Num = ReadNumber<T>();
		
		while (!IsNumberBetween(Num, From, To))
		{
			cout << "\033[91m";
			cout << Message << endl;
			cout << "\033[0m";
			Num = ReadNumber<T>();

		}

		return Num;
	}

	

static	bool IsValidDate(clsDate Date)
	{

		return clsDate::IsValidDate(Date);
	}

static string ReadString()
{
	string  S1 = "";
	// Usage of std::ws will extract allthe whitespace character
	getline(cin >> ws, S1);
	return S1;
}



};

