#pragma once
#include <iostream>
#include "clsDate.h"
class clsPeriod 
{
	clsDate _StartDate;
	clsDate _EndDate;

public:

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{

		_StartDate = StartDate;
		_EndDate = EndDate;


	}

	void SetStartDate(clsDate StartDate)
	{
		_StartDate = StartDate;
	}

	clsDate GetStartDate()
	{
		return _StartDate;
	}
	void SetEndDate(clsDate EndDate)
	{
		_EndDate = EndDate;
	}

	clsDate GetEndDate()
	{
		return _EndDate;
	}

	int PeriodLengthInDays(clsPeriod Period, bool IncludeEndDate =
		false)
	{
		return clsDate::GetDifferenceInDays(Period._StartDate, Period._EndDate,
			IncludeEndDate);
	}
	static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
	{

		if (
			clsDate::CompareDates(Period2._EndDate, Period1._StartDate) == clsDate::enDateCompare::Before
			||
			clsDate::CompareDates(Period2._StartDate, Period1._EndDate) == clsDate::enDateCompare::After
			)
			return false;
		else
			return true;

	}
	bool IsOverlapPeriods(clsPeriod Period2)
	{
		return IsOverlapPeriods(*this, Period2);
	}

	void Print()
	{
		cout << "Period Start: ";
		_StartDate.Print();

		cout << endl;
		cout << "Period End: ";
		_EndDate.Print();


	}

	static bool isDateInPeriod(clsDate Date, clsPeriod Period)
	{
		return !(clsDate::CompareDates(Date, Period._StartDate) ==
			clsDate::enDateCompare::Before
			||
			clsDate::CompareDates(Date, Period._EndDate) ==
			clsDate::enDateCompare::After);
	}
	bool isDateInPeriod(clsDate Date)
	{
		return isDateInPeriod(Date, *this);

	}
	int CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
	{
		int Period1Length = PeriodLengthInDays(Period1, true);
		int Period2Length = PeriodLengthInDays(Period2, true);
		int OverlapDays = 0;
		if (!IsOverlapPeriods(Period1, Period2))
			return 0;
		if (Period1Length < Period2Length)
		{
			while (clsDate::IsDate1BeforeDate2(Period1._StartDate,
				Period1._EndDate))
			{
				if (isDateInPeriod(Period1._StartDate, Period2))
					OverlapDays++;
				Period1._StartDate =
					clsDate::IncreaseDateByOneDay(Period1._StartDate);
			}
		}
		else
		{
			while (clsDate::IsDate1BeforeDate2(Period2._StartDate,
				Period2._EndDate))
			{
				if (isDateInPeriod(Period2._StartDate, Period1))
					OverlapDays++;
				Period2._StartDate =
					clsDate::IncreaseDateByOneDay(Period2._StartDate);
			}
		}
		return OverlapDays;
	}






};

