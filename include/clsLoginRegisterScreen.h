#pragma once
#include <iomanip>
#include <fstream>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsString.h"
#include "clsUtil.h"
class clsLoginRegisterScreen : protected clsScreen
{

private:
   
    static   void _PrintLogRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(25) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(12) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(10) << left << clsUtil::DecryptText(LoginRegisterRecord.Password,4);
        cout << "| " << setw(5) << left << LoginRegisterRecord.Permissions;


    }
public :
    static void ShowRegisterLogList()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pLogScreen))
        {
            return;
        }
        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();


        string Title = "\t  Register Log Screen";
        string SubTitle = "\t    (" + to_string(vLoginRegisterRecord.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date And Time";
        cout << "| " << left << setw(12) << "Username";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(5) << "Pernission";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vLoginRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logs Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord & l : vLoginRegisterRecord)
            {
                _PrintLogRecordLine(l);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};



