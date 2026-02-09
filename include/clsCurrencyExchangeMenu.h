#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsCurrencyListScreen.h"
#include "clsCurrencyFindScreen.h"
#include "clsCurrencyUpdateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;
class clsCurrencyExchangeMenu : protected clsScreen
{
	enum enCurrencyOptions {List=1,Find=2,Update=3,Calculator=4,MainMenu=5};
	static short _ReadTransactionMenuOption()
	{
		cout << clsUtil::Tabs(3) << "choose From [1] To [5]" << endl;
		short Choice = clsInputValidate::ReadNumberBetween(1, 5);
		return Choice;

	}
	static void _PerformMainMenuOption(enCurrencyOptions Choice)
	{
		switch (Choice)
		{
		case enCurrencyOptions::List:

		{
			system("cls");
			_ShowListScreen();
			_GoBackToMainMenue();

		}
		case enCurrencyOptions::Find:

		{
			system("cls");
			_ShowFindScreen();
			_GoBackToMainMenue();


		}
		case enCurrencyOptions::Update:

		{
			system("cls");
			_ShowUpdateScreen();
			_GoBackToMainMenue();


		}
		case enCurrencyOptions::Calculator:

		{
			system("cls");
			_ShowCalculatorScreen();
			_GoBackToMainMenue();

		}
		case enCurrencyOptions::MainMenu:

		{



		}


		}
	}
		static void _ShowUpdateScreen()
		{
			clsCurrencyUpdateScreen::ShowUpdateCurrencyScreen();
		}
		static void _ShowFindScreen()
		{
			clsCurrencyFindScreen::ShowCurrenciesList();
		}
		static void _ShowListScreen()
		{
			clsCurrencyListScreen::ShowCurrenciesList();
		}
		static void _ShowCalculatorScreen()
		{
			clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
		}

		static  void _GoBackToMainMenue()
		{
			cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

			system("pause>0");
			ShowCurrencyExchangeMenu();
		}


public :

	static void ShowCurrencyExchangeMenu()
	{ 
	system("cls");
	_DrawScreenHeader("\tCurrency Exchange Screen");

	cout << setw(37) << left << "" << "===========================================\n";
	cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
	cout << setw(37) << left << "" << "===========================================\n";
	cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
	cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
	cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
	cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
	cout << setw(37) << left << "" << "\t[5] Exit.\n";
	cout << setw(37) << left << "" << "===========================================\n";

	_PerformMainMenuOption((enCurrencyOptions)_ReadTransactionMenuOption());
}
};

