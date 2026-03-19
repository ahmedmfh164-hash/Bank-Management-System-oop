#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
#include<iostream>
#include"clsInputValidate.h"
#include<vector>
#include"clsString.h"
#include"clsUtil.h"

class clsCurrencyCalculator:protected clsScreen
{
private:

	static string _ReadCurrencyCode()
	{
		clsUtil::SetColor(3);
		string CurrencyCode = clsInputValidate::ReadString();
		return CurrencyCode;
	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		clsUtil::SetColor(2);
		cout << "\n--------------------------------------";
		cout << "\nClient Card : ";
		cout << "\n--------------------------------------";
		cout << "\nCountry      : " << Currency.Country();
		cout << "\nCurrency Code: " << Currency.CurrencyCode();
		cout << "\nCurrency Name: " << Currency.CurrencyName();
		cout << "\nRate ($)     : " << Currency.Rate();
		cout << "\n--------------------------------------";

	}
	
	static float _ReadAmount()
	{

		float Amount = 0;
		clsUtil::SetColor(1);
		cout << "\nPlease enter amount to Exchange ? ";
		clsUtil::SetColor(3);
		Amount = clsInputValidate::ReadDblNumber();


		return Amount;
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		while(Continue=='y'||Continue=='Y')
		{
			system("cls");

			_DrawScreenHeader("\t Currency Calculator Screen");

			clsUtil::SetColor(11);
			cout << setw(8) << left << "" << "__________________________________________________________________";
			cout << "__________________________________________\n";
			clsUtil::SetColor(1);
			cout << "\nPlease enter Currency Code to Transfer From : ";
			string CurrencyCode1 = _ReadCurrencyCode();

			clsCurrency SourceCurrency = clsCurrency::FindByCode(CurrencyCode1);
			_PrintCurrency(SourceCurrency);

			clsUtil::SetColor(1);
			cout << "\nPlease enter Currency Code to Transfer To : ";
			string CurrencyCode2 = _ReadCurrencyCode();
			clsCurrency DestinationCurrency = clsCurrency::FindByCode(CurrencyCode2);
			_PrintCurrency(DestinationCurrency);

			float Amount = _ReadAmount();

			cout << "\n" << clsString::UpperAllString(CurrencyCode1) << " = " <<
				SourceCurrency.ConvertToOtherCurrency(Amount, DestinationCurrency)
				<< " " << clsString::UpperAllString(CurrencyCode2) << endl;

			clsUtil::SetColor(1);
			cout << "\nDo You want to perform another calculator Currency ? y/n ? ";
			cin >> Continue;

		}


	}


};

