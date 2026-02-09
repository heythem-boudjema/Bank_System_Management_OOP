#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsCurrency.h"
class clsCurrencyListScreen : protected clsScreen
{

    static void PrintCurrencyLine(clsCurrency Currency)
    {

        cout << "| " << setw(25) << left << Currency.Country();
        cout << "| " << setw(12) << left << Currency.CurrencyCode();
        cout << "| " << setw(20) << left << Currency.CurrencyName();
        cout << "| " << setw(12) << left << Currency.GetRate();
      

    }

public:

    static void ShowCurrenciesList()
    {



        vector <clsCurrency> Currency = clsCurrency::GetAllUSDRates();
        string Title = "Currency List Screen";
        string SubTitle = "(" + to_string(Currency.size()) + ") Currencies";
        _DrawScreenHeader(Title, SubTitle);
        cout << "| " << left << setw(25) << "Country";
        cout << "| " << left << setw(12) << "Currency Code";
        cout << "| " << left << setw(20) << "Currency Name";
        cout << "| " << left << setw(12) << "Rate";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (Currency.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency& C : Currency)
            {

                PrintCurrencyLine(C);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }


};

