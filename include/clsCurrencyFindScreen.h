#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsCurrencyFindScreen : protected clsScreen
{

    static void _PrintCurrencyCard(clsCurrency Currency)
    {
        cout << "Currency Card :" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Country       :" << Currency.Country() << endl;
        cout << "Code          :" << Currency.CurrencyCode() << endl;
        cout << "Name          :" << Currency.CurrencyName() << endl;
        cout << "Rate (1$)=    :" << Currency.GetRate() << endl;
        cout << "--------------------------------------" << endl;


    }
    static void _ShowResult(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "Currency Found" << endl;
            _PrintCurrencyCard(Currency);

       }
        else
        {

            cout << "Currency Not Found" << endl;

        }
    }
public:

    static void ShowCurrenciesList()
    {
        
       
        string Title = "Currency List Screen";
        _DrawScreenHeader(Title);

        cout << "Find By : [1] Code Or [2] Country" << endl;
        short Choice = clsInputValidate::ReadNumberBetween(1, 2);

        if (Choice == 1)
        {
            
                cout << "Please Enter Currency Code" << endl;
                string Code = clsInputValidate::ReadString();
           clsCurrency Currency= clsCurrency::FindByCode(Code);
           _ShowResult(Currency);
        }
        if (Choice == 2)
        {
            cout << "Please Enter Country Name" << endl;
            string Country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResult(Currency);
        }
       



    }


};

