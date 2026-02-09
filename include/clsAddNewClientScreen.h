#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsAddNewClientScreen : protected clsScreen
{

   static void _ReadClientInfo(clsBankClient &Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadNumber<float>();
    }
   static void _PrintClient(clsBankClient Client)
   {
       cout << "\nClient Card:";
       cout << "\n___________________";
       cout << "\nFirstName   : " << Client.FirstName;
       cout << "\nLastName    : " << Client.LastName;
       cout << "\nFull Name   : " << Client.FullName();
       cout << "\nEmail       : " << Client.Email;
       cout << "\nPhone       : " << Client.Phone;
       cout << "\nAcc. Number : " << Client.AccountNumber();
       cout << "\nPassword    : " << Client.PinCode;
       cout << "\nBalance     : " << Client.AccountBalance;
       cout << "\n___________________\n";

   }



public :

	static void AddNewClient()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        _DrawScreenHeader("Add New Client Screen");

        string AccountNumber = "";
        cout << "Please Enter Account Number" << endl;
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "AccountNumber Already exist, Please Enter another account number" << endl;
            AccountNumber = clsInputValidate::ReadString();

        }

        clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);
        cout << "Add New Client Info" << endl;
        cout << "------------------" << endl;

        _ReadClientInfo(Client);
        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client.Save();
        switch (SaveResult)
        {

        case clsBankClient::enSaveResults::svFaildEmptyObject:
            cout << "Error account not saved because is empty" << endl;
            break;
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "Client Added Successfully" << endl;
            _PrintClient(Client);
            break;

        }


    



	}



};

