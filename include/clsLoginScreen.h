#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "CurrentUser.h"
#include "clsMainScreen.h"
class clsLoginScreen : protected clsScreen
{
	
static	bool _Login()
	{
	
	short AttemptsLeftCounter = 3;
		bool LoginFailed = false;
		
		do {
			if (AttemptsLeftCounter == 1)
			{
				cout << "System Locked " << endl;
				return false;
			}
			string Username, Password;
			if (LoginFailed)
			{
				cout << "\033[91m";
				AttemptsLeftCounter--;
				cout << "Invalid UserName Or Password, Please Enter Again" << endl;
				cout << "You have " << AttemptsLeftCounter << " Attempts Left" << endl;
				cout << "\033[0m";
			}
			cout << "Please Enter Username" << endl;
			Username = clsInputValidate::ReadString();
			cout << "Please Enter Password" << endl;
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(Username,Password);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);
		CurrentUser.RegisterLoginInLogFile();
		clsMainScreen::ShowMainMenue();
		return true;
	}


public :
static	bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	


	}




};

