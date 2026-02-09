#pragma once
#include <iostream>
#include "clsUser.h"
#include "CurrentUser.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\t\t" <<"User : " << CurrentUser.UserName;
        cout << "\n\t\t\t\t\t\t" << "Date : "<< clsDate::DateToString(clsDate());
        cout << "\n\t\t\t\t\t______________________________________\n\n";

    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\033[91m";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\033[0m";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

};


