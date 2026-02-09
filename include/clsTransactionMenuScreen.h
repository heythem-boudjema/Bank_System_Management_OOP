#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsDipositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionMenuScreen : protected clsScreen
{
	enum enTransactionMenuOptions { eDiposit = 1, eWithdraw = 2, eTotalBalances = 3,eTransfer=4,eTransferLog=5 ,eMainMenu = 6 };
	static short _ReadTransactionMenuOption()
	{
		cout << clsUtil::Tabs(3) << "choose From [1] To [6]" << endl;
		short Choice = clsInputValidate::ReadNumberBetween(1, 6);
		return Choice;

	}
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowTransactionMenuScreen();
	}

	static void _PerformMainMenuOption(enTransactionMenuOptions Choice)
	{
		switch (Choice)
		{
		case clsTransactionMenuScreen::eDiposit:
		{
			system("cls");
			_ShowDipositScreen();
			_GoBackToMainMenue();
			break;

		}
		case clsTransactionMenuScreen::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToMainMenue();
			break;



		}
		case clsTransactionMenuScreen::eTotalBalances:
		{
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToMainMenue();
			break;

		}
		case clsTransactionMenuScreen::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsTransactionMenuScreen::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsTransactionMenuScreen::eMainMenu:
		{
		
		

		}
		


		}



	}
	static void _ShowDipositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen()
	{
		
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalanceScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}
	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}
public :

	static void ShowTransactionMenuScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}
			system("cls");
			_DrawScreenHeader("\tTransaction Screen");

			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\tTransaction Menu\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] Diposit.\n";
			cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
			cout << setw(37) << left << "" << "\t[3] Show Total Balance.\n";
			cout << setw(37) << left << "" << "\t[4] Transfer.\n";
			cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
			cout << setw(37) << left << "" << "\t[6] Exit.\n";
			cout << setw(37) << left << "" << "===========================================\n";

			_PerformMainMenuOption((enTransactionMenuOptions)_ReadTransactionMenuOption());
		}



	};







