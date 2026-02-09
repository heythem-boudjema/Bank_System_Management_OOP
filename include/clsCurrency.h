#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clsString.h"
using namespace std;
class clsCurrency
{

	enum enMode {EmptyMode=1,UpdateMode=2};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line,string Separator="#//#")
	{
		vector <string> vCurrency = clsString::SplitByDelimiter(Line,Separator);


		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stof(vCurrency[3]));

	}
	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency.CurrencyCode() + Seperator;
		stCurrencyRecord += Currency.CurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.GetRate());

		return stCurrencyRecord;

	}
	static  vector <clsCurrency> _LoadCurrencysDataFromFile()
	{

		vector <clsCurrency> vCurrencys;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				vCurrencys.push_back(Currency);
			}

			MyFile.close();

		}

		return vCurrencys;

	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency &C : vCurrencys)
			{
				DataLine = _ConverCurrencyObjectToLine(C);
				MyFile << DataLine << endl;



			}

			MyFile.close();

		}

	}


	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencysDataFromFile();

		for (clsCurrency& C : _vCurrencys)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(_vCurrencys);

	}





public :
	clsCurrency(enMode Mode,string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;


	}
	static vector <clsCurrency> GetAllUSDRates()
	{

		return _LoadCurrencysDataFromFile();

	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	bool IsEmpty()
	{

		return (_Mode==enMode::EmptyMode);
	}
	float GetRate()
	{
		return _Rate;
	}
	void SetRate(float NewRate)
	{
		_Rate;
	}
	static clsCurrency FindByCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency._CurrencyCode) == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();



	}
	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	static clsCurrency FindByCountry(string CountryName)
	{

		CountryName = clsString::UpperAllString(CountryName);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == CountryName)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();



	}



	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}
	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / GetRate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.GetRate());

	}


};

