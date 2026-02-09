#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsScreen
{

private:

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

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number not Found, Please Enter Another one" << endl;
            cin >> AccountNumber;
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "Please Enter Deposit Amount" << endl;
        double Amount = clsInputValidate::ReadNumber<double>();
        cout << "Are You sure you want to perform this transaction ? Y/n" << endl;
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' or Answer == 'Y')
        {
            Client.Deposit(Amount);
            cout << "Deposit done successfully, New Balance Is " << Client.GetAccountBalance();
        }
        else
        {
            cout << "Operation Canceled" << endl;
        }


    }
};

