#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsUser.h"
#include "CurrentUser.h"
#include "clsUtil.h"
class clsBankClient :public clsPerson
{
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode=2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
    bool _MarkForDelete = false;
    void _Update()
    {
        vector <clsBankClient> vClient = _LoadClientDataFromFile();

        for (clsBankClient& c : vClient)
        {
            if (c.AccountNumber() == AccountNumber())
            {

                c = *this;
                break;

            }



        }
        _SaveVectorDataToFile(vClient);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));

    }
    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
   string _PreparTransferRecord(clsBankClient Destination,double Amount, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += clsDate::GetSystemDateTimeString() + Seperator;
        UserRecord += _AccountNumber + Seperator;
        UserRecord += Destination.AccountNumber() + Seperator;
        UserRecord += to_string(Amount) + Seperator;
        UserRecord += to_string(GetAccountBalance()) + Seperator;
        UserRecord += to_string(Destination.GetAccountBalance()) + Seperator;

        UserRecord +=CurrentUser.GetUserName() ;

        return UserRecord;

    }
  static  clsBankClient _ConvertLineToClientObject(string Line,string Separator="#//#")
    {
        vector <string> vClientData;
        vClientData = clsString::SplitByDelimiter(Line, Separator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], clsUtil::DecryptText(vClientData[5],4), stod(vClientData[6]));

    }
  static  clsBankClient _GetEmptyObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "","", 0);

    }
  static vector<clsBankClient>_LoadClientDataFromFile(string Separator = "#//#")
  {
      vector<clsBankClient> Vinfo;
      string Line;
      fstream file;
      file.open("Clients.txt", ios::in);
      while (getline(file, Line))
      {
         

          clsBankClient info = _ConvertLineToClientObject(Line, Separator);
          Vinfo.push_back(info);
      }
      file.close();
      return Vinfo;
  }
  static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
  {

      string stClientRecord = "";
      stClientRecord += Client.FirstName + Seperator;
      stClientRecord += Client.LastName + Seperator;
      stClientRecord += Client.Email + Seperator;
      stClientRecord += Client.Phone + Seperator;
      stClientRecord += Client.AccountNumber() + Seperator;
      stClientRecord += clsUtil::EncryptText(Client.PinCode,4) + Seperator;
      stClientRecord += to_string(Client.AccountBalance);

      return stClientRecord;

  }

  static vector <clsBankClient> _SaveVectorDataToFile(vector <clsBankClient>& Vclient)
  {
      vector <clsBankClient> NewVictor;
      fstream file;
      file.open("Clients.txt", ios::out);
      string Line;
      if (file.is_open())
      {
          for (clsBankClient& i : Vclient)
          {
              if (i._MarkForDelete == false)
              {
                  Line = _ConverClientObjectToLine(i);
                  file << Line << endl;
              }

          }
          file.close();

      }
      return NewVictor;
  }



public :
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
	{

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;

	}

    struct stTransferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float Amount;
        float SourceBalance;
        float DestinationBalance;
        string User;

    };
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 ,FaildAccountExist=2};
    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }
        case enMode::UpdateMode:
        {

            _Update();
            return enSaveResults::svSucceeded;


        }
        case enMode::AddNewMode:
        {
            if (IsClientExist(_AccountNumber))
            {
                return enSaveResults::FaildAccountExist;
}
            else
            {
                _AddNew();
                _Mode=enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
        }




        }

}

   static clsBankClient Find(string AccountNumber)
    {
        vector <clsBankClient> vClient;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {

               clsBankClient Client = _ConvertLineToClientObject(Line);
               if (Client.AccountNumber() == AccountNumber)
               {
                   MyFile.close();
                   return Client;
                }

               vClient.push_back(Client);

            }

            MyFile.close();
        }

        return _GetEmptyObject();
    }
   static clsBankClient Find(string AccountNumber,string PinCode)
    {
        vector <clsBankClient> vClient;
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

                vClient.push_back(Client);

            }

            MyFile.close();
        }

        return _GetEmptyObject();
    }
   static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client = Find(AccountNumber);
        return (!Client.IsEmpty());
    }
   static clsBankClient GetAddNewClientObject(string AccountNumber)
   {
       return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
   }
   bool Delete()
   {
       vector <clsBankClient> vClient = _LoadClientDataFromFile();
       for (clsBankClient& c : vClient)
       {
           if (c.AccountNumber() == _AccountNumber)
           {
               c._MarkForDelete = true;
               break;
           }

       }
       _SaveVectorDataToFile(vClient);
       *this = _GetEmptyObject();
       return true;

   }
   static vector <clsBankClient> GetClientsList()
   {
       return _LoadClientDataFromFile();
   }
   static float GetTotalBalances()
   {
       vector <clsBankClient> vClient = GetClientsList();
       float TotalBalances = 0;
       for (clsBankClient& c : vClient)
       {
           TotalBalances = +c.AccountBalance;
       }

       return TotalBalances;
   }

   void Deposit(double Amount)
   {
       _AccountBalance += Amount;
       Save();
   }
   bool Withdraw(double Amount)
   {
       if (Amount > _AccountBalance)
       {
           return false;


       }
       else
       {

           _AccountBalance -= Amount;
           Save();
       }
   }
   bool Transfer(float Amount, clsBankClient& Destination)
   {
       if (Amount > AccountBalance)
       {
           return false;
}
       else
       {
           Withdraw(Amount);
           Destination.Deposit(Amount);
           _RegisterTransferInLogFile(Destination,Amount);
           return true;

       }



   }
    void _RegisterTransferInLogFile(clsBankClient Destination, float Amount,string FileName = "TransferLog.txt")
   {
       fstream MyFile;
       MyFile.open(FileName, ios::out | ios::app);

       if (MyFile.is_open())
       {

           MyFile << _PreparTransferRecord(Destination,Amount) << endl;

           MyFile.close();
       }

   }
    static stTransferLogRecord ConvertTranferLogLineToStruct(string Line)
    {
        vector <string> vLog = clsString::SplitByDelimiter(Line);
        clsBankClient::stTransferLogRecord Client;
        Client.DateTime = vLog[0];
        Client.SourceAccountNumber = vLog[1];
        Client.DestinationAccountNumber = vLog[2];
        Client.Amount = stof(vLog[3]);
        Client.SourceBalance = stof(vLog[4]);
        Client.DestinationBalance = stof(vLog[5]);
        Client.User = vLog[6];
        return Client;

    }
    static  vector <stTransferLogRecord> GetTransferLogList(string FileName = "TransferLog.txt")
    {

        vector <clsBankClient::stTransferLogRecord> vUsers;
        clsBankClient::stTransferLogRecord Client;
        fstream MyFile;
        MyFile.open(FileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {

                Client = ConvertTranferLogLineToStruct(Line);

                vUsers.push_back(Client);
            }

            MyFile.close();

        }

        return vUsers;

    }
};

