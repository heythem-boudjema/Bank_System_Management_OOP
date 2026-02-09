#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyUpdateScreen : protected clsScreen
{
    static float _ReadNewRate()
    {
        float NewRate = 0;
        cout << "Please Enter New Rate" << endl;
        NewRate = clsInputValidate::ReadNumber<float>();
        return NewRate;
    }

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
 
public:

    static void ShowUpdateCurrencyScreen()
    {


        string Title = "Currency Update Screen";
        _DrawScreenHeader(Title);

        cout << "Please Enter Currency Code" << endl;
        string Code = clsInputValidate::ReadString();
        clsCurrency Currency = clsCurrency::FindByCode(Code);
        while (Currency.IsEmpty())
        {
            cout << "Currency Not Found, Please Enter Another Currency Code" << endl;
            Code = clsInputValidate::ReadString();
            Currency = clsCurrency::FindByCode(Code);
        }
        _PrintCurrencyCard(Currency);

            char Answer = 'n';
            cout << "Are You Sure You Want To Update This Currency Y/N" << endl;
            cin >> Answer;
            if (Answer == 'y' or Answer == 'Y')
            {
                cout << "Currency Update Screen" << endl;
                cout << "----------------------------\n" << endl;
                Currency.UpdateRate(_ReadNewRate());
                cout << "\nCurrency Rate Updated Successfully\n" << endl;
                _PrintCurrencyCard(Currency);
            }
            else
            {

                cout << "Currency Not Updated!" << endl;

            }



        }

    
};