#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <string>
#include <Vector>
#include "clsString.h"
using namespace std;
class clsDate
{
	int _Year;
	int _Month;
	int _Day;
	

	static string PrintMonthsName(short Month)
	{
		string Arr[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return Arr[Month - 1];
	}
	static void PrintCalendarName(short Year)
	{
		printf("\n             Calendar - %d\n", Year);
	}

public:
	clsDate()
	{
		time_t now = time(0);
		tm* localTime = localtime(&now);

		_Year = 1900 + localTime->tm_year;
		_Month = 1 + localTime->tm_mon;
		_Day = localTime->tm_mday;
	}
	clsDate(string Date)
	{
		vector <string> vDate;
		vDate = SplitString(Date, "/");
		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);

	}
	clsDate(int Day, int Month, int Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	clsDate(int Days, int Year)
	{
		clsDate Date = GetDateFromDayOrderInYear(Days, Year);
		_Year = Date._Year;
		_Month = Date._Month;
		_Day = Date._Day;


	}
	void SetDay(int Day)
	{
		_Day = Day;
	}
	int GetDay()
	{
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) int Day;
	void SetMonth(int Month)
	{
		_Month = Month;
	}
	int GetMonth()
	{
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) int Month;
	void SetYear(int Year)
	{
		_Year = Year;
	}
	int GetYear()
	{
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) int Year;

	void Print()
	{
		cout << DateToString(*this);
	}
	static void Print(clsDate Date)
	{
		cout << DateToString(Date);
	}


	static clsDate GetSystemDate()
	{
		clsDate Date;
		time_t t = time(0);
		tm* now = localtime(&t);
		short _Day, _Month, _Year;
		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
		return clsDate(_Year, _Month, _Day);
	}
	static string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}
	static bool IsLeapYear(short Year)
	{
		return ((Year % 4 == 0 && Year % 100 != 0) or (Year % 400 == 0));

	}
	bool IsLeapYear()
	{
		Year = _Year;
		return ((Year % 4 == 0 && Year % 100 != 0) or (Year % 400 == 0));

	}

	static short NumberOfDaysInYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;

	}
	short NumberOfDaysInYear()
	{
		return IsLeapYear(_Year) ? 366 : 365;
	}
	static short NumberOfHoursInYear(short Year)
	{
		return 24 * (NumberOfDaysInYear(Year));

	}
	short NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}
	static int NumberOfMinutesInYear(short Year)
	{
		return 60 * (NumberOfHoursInYear(Year));

	}
	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(_Year);
	}
	static int NumberOfSecondsInYear(short Year)
	{
		return 60 * (NumberOfMinutesInYear(Year));

	}
	int NumberOfSecondsInYear()
	{
		NumberOfSecondsInYear(_Year);
	}
	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;
		if (Month == 2)
		{
			return IsLeapYear(Year) ? 29 : 28;
		}
		short arr31Days[7] = { 1,3,5,7,8,10,12 };
		for (short i = 1; i <= 7; i++)
		{
			if (arr31Days[i - 1] == Month)
				return 31;
		}
		return 30;
	}
	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Month, _Year);
	}

	static short NumberOfHoursInMonth(short Year, short Month)
	{
		return 24 * (NumberOfDaysInAMonth(Year, Month));

	}
	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Year, _Month);
	}
	static int NumberOfMinutesInMonth(short Year, short Month)
	{
		return 60 * (NumberOfHoursInMonth(Year, Month));

	}
	int NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Year, _Month);
	}

	static int NumberOfSecondsInMonth(short Year, short Month)
	{
		return 60 * (NumberOfMinutesInMonth(Year, Month));

	}
	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Year, _Month);
	}
	static short SearchForTheDay(short Year, short Month, short Day)
	{
		short d;
		short a = (14 - Month) / 12;
		short y = Year - a;
		short m = Month + (12 * a) - 2;
		return d = ((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);

	}
	short SearchForTheDay()
	{
		return SearchForTheDay(_Year, _Month, _Day);
	}
	static void PrintCalendarOfMonth(short Year, short Month)
	{
		short FirstDay = SearchForTheDay(Year, Month, 1);
		short NumberOfDays = NumberOfDaysInAMonth(Year, Month);

		printf("\n------------------%s------------------\n", PrintMonthsName(Month).c_str());
		printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		int i;
		for (i = 0; i < FirstDay; i++)
		{
			printf("     ");
		}
		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n---------------------------------------");
	}
	void PrintCalendarOfMonth()
	{

		PrintCalendarOfMonth(_Year, _Month);

	}
	static void PrintCalendarOfYear(short Year)
	{
		PrintCalendarName(Year);
		for (int i = 1; i < 13; i++)
		{
			PrintCalendarOfMonth(Year, i);

		}

	}
	void PrintCalendarOfYear()
	{
		PrintCalendarOfYear(_Year);

	}
	static short DaysNumberFromBegeningOfTheYear(short Year, short Month, short Day)
	{
		short NumberOfDays = 0;
		for (int i = 1; i < Month; i++)
		{
			NumberOfDays += NumberOfDaysInAMonth(Year, i);

		}

		return NumberOfDays + Day;
	}
	short DaysNumberFromBegeningOfTheYear()
	{
		return DaysNumberFromBegeningOfTheYear(_Year, _Month, _Day);
	}
	clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		Date._Year = Year;
		Date._Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._Month, Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : ((Date1._Year ==
			Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month ==
				Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}
	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}
	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._Month ==
			Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false)
			: false) : false;
	}
	bool IsDate1EqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}
	static bool IsLastDay(clsDate Date)
	{
		return (Date._Day == NumberOfDaysInAMonth(Date._Month,
			Date._Year));
	}
	bool IsLastDay()
	{
		return IsLastDay(*this);
	}
	static bool IsLastMonth(short Month)
	{
		return (Month == 12);
	}
	bool IsLastMonth()
	{
		return IsLastMonth(_Month);
	}
	static clsDate IncreaseDateByOneDay(clsDate &Date)
	{
		if (IsLastDay(Date))
		{
			if (IsLastMonth(Date._Month))
			{
				Date._Month = 1;
				Date._Day = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}
		return Date;
	}
	void IncreaseDateByOneDay()
	{
		IncreaseDateByOneDay(*this);
	}
	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate._Year = Date1._Year;
		TempDate._Month = Date1._Month;
		TempDate._Day = Date1._Day;
		Date1._Year = Date2._Year;
		Date1._Month = Date2._Month;
		Date1._Day = Date2._Day;
		Date2._Year = TempDate._Year;
		Date2._Month = TempDate._Month;
		Date2._Day = TempDate._Day;
	}
	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool
		IncludeEndDay = false)
	{
		int Days = 0;
		short SawpFlagValue = 1;
		if (!IsDate1BeforeDate2(Date1, Date2))
		{
		
			SwapDates(Date1, Date2);
			SawpFlagValue = -1;
		}
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SawpFlagValue : Days *
			SawpFlagValue;
	}

	static int CalculatAgeInDays(clsDate Date1,bool IncludeEndDay=true)
	{
		clsDate Date2 = GetSystemDate();
		return GetDifferenceInDays(Date1, Date2, IncludeEndDay);
	}
	int CalculatAgeInDays()
	{
		return CalculatAgeInDays(*this);

	}


	
	static clsDate IncreaseDateByOneWeek(clsDate &Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}
	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate &Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreaseDateByXWeeks(short Weeks)
	{
		IncreaseDateByXWeeks(Weeks, *this);
	}
	static clsDate IncreaseDateByOneMonth(clsDate& Date)
	{

		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}
	void IncreaseDateByOneMonth()
	{

		IncreaseDateByOneMonth(*this);

	}
	static clsDate IncreaseDateByXDays(short Days, clsDate& Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByXDays(short Days)
	{

		IncreaseDateByXDays(Days, *this);
	}
	static clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void IncreaseDateByXMonths(short Months)
	{
		IncreaseDateByXMonths(Months, *this);
	}
	static clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date.Year++;
		return Date;
	}
	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(short Years, clsDate& Date)
	{
		Date.Year += Years;
		return Date;

	}

	void IncreaseDateByXYears(short Years)
	{
		IncreaseDateByXYears(Years,*this);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& Date)
	{
		//Period of 10 years
		Date.Year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(short Decade, clsDate& Date)
	{
		Date.Year += Decade * 10;
		return Date;
	}

	void IncreaseDateByXDecades(short Decade)
	{
		IncreaseDateByXDecades(Decade, *this);
	}

	static clsDate IncreaseDateByOneCentury(clsDate& Date)
	{
		//Period of 100 years
		Date.Year += 100;
		return Date;
	}

	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		//Period of 1000 years
		Date.Year += 1000;
		return Date;
	}

	void IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Month = 12;
				Date.Day = 31;
				Date.Year--;
			}
			else
			{

				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}

		return Date;
	}
	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}
	static clsDate DecreaseDateByOneWeek(clsDate& Date)
	{

		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}
	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}
	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
	{

		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void DecreaseDateByXWeeks(short Weeks)
	{
		DecreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{

		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
			Date.Month--;


		//last check day in date should not exceed max days in the current month
	   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
	   // be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}


		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByXDays(short Days)
	{
		DecreaseDateByXDays(Days, *this);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate& Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short Months)
	{
		DecreaseDateByXMonths(Months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date)
	{

		Date.Year--;
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
	{

		Date.Year -= Years;
		return Date;
	}

	void DecreaseDateByXYears(short Years)
	{
		DecreaseDateByXYears(Years, *this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date)
	{
		//Period of 10 years
		Date.Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
	{

		Date.Year -= Decades * 10;
		return Date;
	}

	void DecreaseDateByXDecades(short Decades)
	{
		DecreaseDateByXDecades(Decades, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& Date)
	{
		//Period of 100 years
		Date.Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& Date)
	{
		//Period of 1000 years
		Date.Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}


	static short SearchForTheDay(clsDate Date)
	{
		return SearchForTheDay(Date._Year, Date._Month, Date._Day);


	}
	
	string DayNameInDate(short DayNumber)
	{
		string Array[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return Array[DayNumber];

	}
	static bool IsEndOfWeek(clsDate Date)
	{
		return (SearchForTheDay(Date) == 6);
	}
	bool IsEndOfWeek()
	{
		return  IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		short DayIndex = SearchForTheDay(Date);
		return (DayIndex == 5 or DayIndex == 6);

	}
	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}
	static bool IsBuissnessDay(clsDate Date)
	{

		return (!IsWeekEnd(Date)) ? true : false;

	}
	bool IsBuissnessDay()
	{
		return IsBuissnessDay(*this);
	}
	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - SearchForTheDay(Date);
	}
	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}
   static int DifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int counter = 0;

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Date1 = IncreaseDateByOneDay(Date1);

			counter++;


		}


		return IncludeEndDay ? ++counter : counter;

	}
   int DifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
   {
	   return DifferenceInDays(*this, Date2, IncludeEndDay);
   }
	static short DaysUntilTheEndOfMonth(clsDate Date)
	{
		clsDate Date2;
		Date2._Year = Date._Year;
		Date2._Month = Date._Month;
		Date2._Day = NumberOfDaysInAMonth(Date._Year, Date._Month);

		return DifferenceInDays(Date, Date2, true);
	}
	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}
	static short DaysUntilTheEndOfYear(clsDate Date)
	{
		clsDate Date2;
		Date2._Year = Date._Year;
		Date2._Month = 12;
		Date2._Day = 31;

		return DifferenceInDays(Date, Date2, true);
	}
	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		short DaysCount = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBuissnessDay(DateFrom))
				DaysCount++;
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return DaysCount;
	}

	clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		//in case the data  is weekend keep adding one day util you reach business day
		//we get rid of all weekends before the first business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//here we increase the vacation dates to add all weekends to it.

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//in case the return date is week end keep adding one day util you reach business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) &&
			!IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDate1AfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}
	enum enDateCompare { Before = -1, Equal = 0, After = 1 };
	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;
		/* if (IsDate1AfterDate2(Date1,Date2))
		return enDateCompare::After;*/
		//this is faster
		return enDateCompare::After;

	}
	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}
	
	
	
	static bool IsValidDate(clsDate Date)
	{
		if (Date._Day < 1 || Date._Day>31)
			return false;
		if (Date._Month < 1 || Date._Month>12)
			return false;
		if (Date._Month == 2)
		{
			if (IsLeapYear(Date._Year))
			{
				if (Date._Day > 29)
					return false;
			}
			else
			{
				if (Date._Day > 28)
					return false;
			}
		}
		short DaysInMonth = NumberOfDaysInAMonth(Date._Month,
			Date._Year);
		if (Date._Day > DaysInMonth)
			return false;
		return true;
	}
 bool IsValid()
	{
		return IsValidDate(*this);
	}
	vector<string> SplitString(string S1, string Delim)
	{
		vector<string> vString;
		short pos = 0;
		string sWord; // define a string variable
		// use find() function to get the position of the delimiters
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				vString.push_back(sWord);
			}
			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}
		return vString;
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) +
			"/" + to_string(Date.Year);
	}
	string DateToString()
	{
		return to_string(_Day) + "/" + to_string(_Month) +
			"/" + to_string(_Year);
	}
	clsDate StringToDate(string DateString)
	{
		clsDate Date;
		vector <string> vDate;
		vDate = SplitString(DateString, "/");
		Date._Day = stoi(vDate[0]);
		Date._Month = stoi(vDate[1]);
		Date._Year = stoi(vDate[2]);
		return Date;
	}
	string ReadStringDate(string Message)
	{
		string DateString;
		cout << Message;
		getline(cin >> ws, DateString);
		return DateString;
	}
	string ReplaceWordInString(string S1, string StringToReplace,
		string sRepalceTo)
	{
		short pos = S1.find(StringToReplace);
		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(),
				sRepalceTo);
			pos = S1.find(StringToReplace);//find next
		}
		return S1;
	}
	string FormateDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";
		FormattedDateString = ReplaceWordInString(DateFormat, "dd",
			to_string(Date._Day));
		FormattedDateString = ReplaceWordInString(FormattedDateString,
			"mm", to_string(Date._Month));
		FormattedDateString = ReplaceWordInString(FormattedDateString,
			"yyyy", to_string(Date._Year));
		return FormattedDateString;
	}






































	
	

	};

