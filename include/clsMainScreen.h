#pragma once
#include <iomanip>
#include <iostream>
#include <sstream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionMenuScreen.h"
#include "clsManageUserScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMenu.h"
using namespace std;
class clsMainScreen : protected clsScreen
{
	enum enMainMenuOptions {eShowClient=1,eAddNewClient=2,eDeleteClient=3,eUpdateClient=4,eFindClient=5,eTransaction=6,eManageUsers=7,eLogRegister,eCurrencyExchange=9,eExit=10
	};


	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 10);
		return Choice;

	}
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}
	static void _PerformMainMenuOption(enMainMenuOptions Choice)
	{
		switch (Choice)
		{
		case enMainMenuOptions::eShowClient:
		{
			system("cls");
			_ShowClientList();
			_GoBackToMainMenue();
			break;

		}
		case enMainMenuOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;



		}
		case enMainMenuOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;

		}
		case enMainMenuOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;

		}
		case enMainMenuOptions::eTransaction:
		{
			system("cls");
			_ShowTransactionMenuScreen();
			_GoBackToMainMenue();
			break;

		}
		case enMainMenuOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;



		}
		case enMainMenuOptions::eManageUsers:
		{
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
			break;

		}
		case enMainMenuOptions::eExit:
		{
			system("cls");
			_ExitMenuScreen();

			break;



		}
		case enMainMenuOptions::eLogRegister:
		{
			system("cls");
			_ShowRegisterLogScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenuOptions::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
			break;

		}
}



	}
	static void _PermissionColor(clsUser User, clsUser::enPermissions Permission, string Message, bool NoNeedPermission = false)
	{
		if (User.CheckPermission(Permission) or NoNeedPermission==true)
			cout << "\033[92m";
		else
			cout << "\033[91m";
		cout << Message << endl;
		cout << "\033[0m";
	}
	static void _ShowClientList()
	{
		clsClientListScreen::ShowClientsList();
	}
	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::AddNewClient();
	}
	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}
	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowTransactionMenuScreen()
	{
		clsTransactionMenuScreen::ShowTransactionMenuScreen();
	}
	static void _ShowManageUsersScreen()
	{
		clsManageUsersScreen::ShowManageUsersMenu();
	}
	static void _ShowRegisterLogScreen()
	{
		clsLoginRegisterScreen::ShowRegisterLogList();
	}
	static void _ExitMenuScreen()
	{
		_Logout();

	}
	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeMenu::ShowCurrencyExchangeMenu();
	}
	static void _MainMenuList()
	{
		struct Option {
			clsUser::enPermissions perm;
			string text;
		};
		Option options[10] = {
		{clsUser::pListClients,   "[1] List Clients"},
		{clsUser::pAddNewClient,  "[2] Add New Client"},
		{clsUser::pDeleteClient,  "[3] Delete Client"},
		{clsUser::pUpdateClients, "[4] Update Client Info"},
		{clsUser::pFindClient,    "[5] Find Client"},
		{clsUser::pTranactions,  "[6] Transactions"},
		{clsUser::pManageUsers,   "[7] Manage Users"},
		{clsUser::pLogScreen,     "[8] Login Register"},
		{clsUser::pManageUsers,   "[9] Currency Exchange"},
		{clsUser::pLogScreen,     "[10] Logout"},
		};
		for (int i = 0; i < 10; i++)
		{
			ostringstream out;
			out << setw(37) << left << "" << "\t" << options[i].text;

			if (i == 8 || i == 9) 
				_PermissionColor(CurrentUser, options[i].perm, out.str(), true);
			else
				_PermissionColor(CurrentUser, options[i].perm, out.str());
		}



	}
public :



	static void ShowMainMenue()
	{

		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		
		_MainMenuList();
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
	}












};

