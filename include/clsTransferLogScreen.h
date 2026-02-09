#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsString.h"

class clsTransferLogScreen :protected clsScreen
{

private:
    
    static void PrintTransferRecordLine(clsBankClient::stTransferLogRecord Client)
    {

        cout << "| " << setw(20) << left << Client.DateTime;
        cout << "| " << setw(10) << left << Client.SourceAccountNumber;
        cout << "| " << setw(10) << left << Client.DestinationAccountNumber;
        cout << "| " << setw(10) << left << Client.Amount;
        cout << "| " << setw(10) << left << Client.SourceBalance;
        cout << "| " << setw(10) << left << Client.DestinationBalance;
        cout << "| " << setw(10) << left << Client.User;

    }
   
public:


    static void ShowTransferLogScreen()
    {

       

        vector <clsBankClient::stTransferLogRecord> vClients = clsBankClient::GetTransferLogList();
        string Title = "Transfer Log Screen";
        string SubTitle = "(" + to_string(vClients.size()) + ") Clients";
        _DrawScreenHeader(Title, SubTitle);
        cout << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(10) << "S.Account";
        cout << "| " << left << setw(10) << "D.Account";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "S.Balance";
        cout << "| " << left << setw(10) << "D.Balance";
        cout << "| " << left << setw(10) << "User";

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord& Client : vClients)
            {

                PrintTransferRecordLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

