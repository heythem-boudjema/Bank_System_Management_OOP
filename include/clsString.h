#pragma once
#include <iostream>
#include <string>
#include <Vector>

using namespace std;

class clsString
{
	string _Value;

	
public :
	static string JoinString(string arrString[], short Length, string Delim)
	{

		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());

	}
	static string ReverseWordsInString(string S1)
	{

		vector<string> vString;
		string S2 = "";

		vString = SplitBySpaces(S1);

		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{

			--iter;

			S2 += *iter + " ";

		}

		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	static char InverseCharacter(char C)
	{

		return islower(C) ? toupper(C) : tolower(C);


	}
	static short CharacterCounter(string Input, char C, bool MatchCase = true)
	{
		short counter = 0;


		for (short i = 0; i < Input.length(); i++)
		{
			if (MatchCase)
			{
				if (Input[i] == C)
				{
					counter++;
				}
			}
			else
			{
				if (tolower(Input[i]) == tolower(C))
					counter++;

			}


		}
		return counter;
	}
	static bool IsVowel(char C)
	{
		C = tolower(C);
		return ((C == 'a') || (C == 'e') || (C == 'i') || (C == 'y') || (C == 'o') || (C == 'u'));
	}
	static void PrintFirstLetterOfEachWord(string Name)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < Name.length(); i++)
		{
			if (Name[i] != ' ' && IsFirstLetter)
			{
				cout << Name[i] << endl;

			}

			IsFirstLetter = (Name[i] == ' ' ? true : false);

		}


	}
	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}
	static string UpperFirstLetterOfEachWord(string Name)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < Name.length(); i++)
		{
			if (Name[i] != ' ' && IsFirstLetter)
			{

				Name[i] = toupper(Name[i]);


			}
			IsFirstLetter = (Name[i] == ' ' ? true : false);

		}
		return Name;
	}
	void UpperFirstLetterOfEachWord()
	{
		_Value=UpperFirstLetterOfEachWord(_Value);
	}
	static string LowerFirstLetterOfEachWord(string Name)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < Name.length(); i++)
		{
			if (Name[i] != ' ' && IsFirstLetter)
			{

				Name[i] = tolower(Name[i]);


			}
			IsFirstLetter = (Name[i] == ' ' ? true : false);

		}
		return Name;
	}
	void LowerFirstLetterOfEachWord()
	{

		_Value=LowerFirstLetterOfEachWord(_Value);

	}
	static string UpperAllString(string Name)
	{

		for (short i = 0; i < Name.length(); i++)
		{
			Name[i] = toupper((Name[i]));
		}
		return Name;

	}
	void UpperAllString()
	{
		_Value=UpperAllString(_Value);
	}
	static string LowerAllString(string Name)
	{

		for (short i = 0; i < Name.length(); i++)
		{
			Name[i] = tolower((Name[i]));
		}
		return Name;
	}
	void LowerAllString()
	{
		_Value=LowerAllString(_Value);
	}
	static string InverseAllLetters(string Name)
	{

		for (int i = 0; i < Name.length(); i++)
		{
			Name[i] = InverseCharacter(Name[i]);

		}
		return Name;

	}
	string InverseAllLetters()
	{
		_Value=InverseAllLetters(_Value);
	}

	static short CountSmallLetters(string Input)
	{
		short SmallLetters = 0;
		for (short i = 0; i < Input.length(); i++)
		{
			if (Input[i] != ' ' && islower(Input[i]))
			{
				SmallLetters++;
			}


		}
		return SmallLetters;
	}
	short CountSmallLetters()
	{
		CountSmallLetters(_Value);

	}
static	short CountCapitalLetters(string Input)
	{
		short CapitalLetters = 0;
		for (short i = 0; i < Input.length(); i++)
		{
			if (Input[i] != ' ' && isupper(Input[i]))
			{
				CapitalLetters++;
			}


		}
		return CapitalLetters;
	}
	short CountCapitalLetters()
	{
		CountCapitalLetters(_Value);
	}

static	short CountSpecificLetterSensitive(string Input, char C)
	{
		return CharacterCounter(Input,C,true);
	}
	short CountSpecificLetterSensitive(char C)
	{
		return CharacterCounter(_Value, C, true);
	}
static	short CountSpecificLetterInsensitive(string Input, char C)
	{
		return CharacterCounter(Input, C, false);
	}
	short CountSpecificLetterInsensitive(char C)
	{
		return CharacterCounter(_Value, C, false);
	}
static	short CountVowels(string Input)
	{
		short counter = 0;
		for (short i = 0; i < Input.length(); i++)
		{
			if (IsVowel(Input[i]))
			{
				counter++;
			}

		}
		return counter;
	}
	short CountVowels()
	{

		return CountVowels(_Value);

	}
static	void PrintVowels(string Input)
	{
		for (short i = 0; i < Input.length(); i++)
		{
			if (IsVowel(Input[i]))
			{
				cout << Input[i] << "   ";
			}

		}
	}
	void PrintVowels()
	{
		PrintVowels(_Value);
	}
	static void PrintEachWord(string S1)
	{
		short Pos = 0;
		string Space = " ";
		string Word;
		while ((Pos = S1.find(Space)) != std::string::npos)
		{
			Word = S1.substr(0, Pos);
			if (Word != "")
			{
				cout << Word << endl;
			}

			S1.erase(0, Pos + Space.length());
		}

		if (S1 != "")
		{
			cout << S1 << endl;
		}



	}
	void PrintEachWord()
	{
		PrintEachWord(_Value);
	}
static 	short CountWord(string S1)
	{
		short counter = 0;
		short Pos = 0;
		string Space = " ";
		string Word;
		while ((Pos = S1.find(Space)) != std::string::npos)
		{
			Word = S1.substr(0, Pos);
			if (Word != "")
			{
				counter++;
			}

			S1.erase(0, Pos + Space.length());
		}

		if (S1 != "")
		{
			counter++;
		}


		return counter;
	}
	short CountWord()
	{
		CountWord(_Value);
	}
static	string TrimLeft(string S1)
	{


		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, (S1.length() - i));
			}

		}

		return "";


	}
	string TrimLeft()
	{
		TrimLeft(_Value);
	}
static	string TrimRight(string S1)
	{


		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}

		}

		return "";
	}
	string TrimRight()
	{
		return TrimRight(_Value);
	}
	static string FullTrim(string S1)
	{
		return TrimLeft(TrimRight(S1));


	}
	string FullTrim()
	{
		return FullTrim(_Value);
	}

	static string AddDelimiterToString(string S1, string Delim)
	{
		string s1;
		vector <string> v1 = SplitBySpaces(S1);
		s1 = JoinString(v1, Delim);
		return s1;

	}
	string AddDelimiterToString(string Delim)
	{
		return AddDelimiterToString(_Value, Delim);
	}


	


	static string ReplaceWordSensitiveCase(string S1, string
		StringToReplace, string sRepalceTo, bool MatchCase = true)
	{
		vector<string> vString = SplitBySpaces(S1);
		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}
			}
			else
			{
				if (LowerAllString(s) ==
					LowerAllString(StringToReplace))
				{
					s = sRepalceTo;
				}
			}
		}
		return JoinString(vString, " ");
	}
	string ReplaceWordSensitiveCase(string S1, string StringToReplace, string sRepalceTo)
	{
		return ReplaceWordSensitiveCase(_Value,
			StringToReplace, sRepalceTo, true);
	}

	static string ReplaceWordInsensitiveCase(string S1, string
		StringToReplace, string sRepalceTo)
	{
		return ReplaceWordSensitiveCase(S1, StringToReplace,sRepalceTo, false);
	}
	 string ReplaceWordInsensitiveCase(string
		StringToReplace, string sRepalceTo)
	{
		return ReplaceWordSensitiveCase(_Value, StringToReplace, sRepalceTo, false);
	}

	static string RemovePunct(string s1)
	{
		string s2 = "";
		for (int i = 0; i < s1.length(); i++)
		{
			if (!ispunct(s1[i]))
			{
				s2 = s2 + s1[i];
			}

		}
		return s2;


	}
	string RemovePunct()
	{
		return RemovePunct(_Value);

	}


	static vector <string> SplitByDelimiter(string S1, string Delimiter="#//#")
	{
		vector <string> Spliter;
		short Pos = 0;
		string Word;
		while ((Pos = S1.find(Delimiter)) != std::string::npos)
		{
			Word = S1.substr(0, Pos);
			if (Word != "")
			{
				Spliter.push_back(Word);

			}

			S1.erase(0, Pos + Delimiter.length());
		}

		if (S1 != "")
		{
			Spliter.push_back(S1);

		}
		return Spliter;

	}
	static 	vector <string> SplitBySpaces(string S1)
	{
		vector <string> v1;
		return v1 = SplitByDelimiter(S1, " ");

	}



public:
	clsString()
	{
		_Value = "";
	}
	clsString(string Value)
	{
		_Value = Value;
	}
	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;
	static short Length(string s1)
	{
		return s1.length();
	}
	short Length()
	{
		return _Value.length();
	}
	static string JoinString(vector<string> vString, string Delim)
	{
		string s1 = "";
		for (string& i : vString)
		{
			s1 = s1 + i + Delim;

		}
		return (s1.substr(0, (s1.length() - Delim.length())));
	}
};

