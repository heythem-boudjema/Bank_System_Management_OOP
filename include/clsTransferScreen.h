#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber(string Message= "Please enter AccountNumber ?" )
    {
        string AccountNumber = "";
        cout << Message << endl;
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t  Transfer Screen");
        string SourceAccountNumber = _ReadAccountNumber("Please enter AccountNumber to transfer from");
        while (!clsBankClient::IsClientExist(SourceAccountNumber))
        {
            cout << "Account Number not Found, Please Enter Another one" << endl;
            cin >> SourceAccountNumber;
        }

        clsBankClient SourceClient = clsBankClient::Find(SourceAccountNumber);
        _PrintClient(SourceClient);

        string DestinationAccountNumber = _ReadAccountNumber("Please enter AccountNumber to transfer to");
        while (!clsBankClient::IsClientExist(DestinationAccountNumber))
        {
            cout << "Account Number not Found, Please Enter Another one" << endl;
            DestinationAccountNumber = clsInputValidate::ReadString();
        }
        while (SourceAccountNumber == DestinationAccountNumber)
        {
            cout << "You cant transfer to the same account, please enter another account number" << endl;
            DestinationAccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient DestinationClient = clsBankClient::Find(DestinationAccountNumber);
        
        _PrintClient(DestinationClient);

        cout << "Please Enter Transfer Amount" << endl;
        double Amount = clsInputValidate::ReadNumber<double>();
        while (Amount > SourceClient.GetAccountBalance())
        {
            cout << "Amount exceed The Balance Avalaible, Please Choose Another Amount" << endl;
            Amount = clsInputValidate::ReadNumber<double>();
        }
        cout << "Are You sure you want to perform this transaction ? Y/n" << endl;
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' or Answer == 'Y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient))
            {
                cout << "\nTransfer done successfully\n";
                _PrintClient(SourceClient);
                _PrintClient(DestinationClient);
            }
            else
            {
                cout << "\nTransfer Faild\n";

            }
        
        }
        else
        {
            cout << "Operation Canceled" << endl;
        }


    }
};


