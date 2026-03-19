#pragma once
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUtil.h"

class clsFindCurrency:protected clsScreen
{
private:

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

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found:-)\n";
            _PrintCurrency(Currency);

        }
        else
            cout << "\nCurrency Was Not Found:-(\n";
    }

public:

    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\tFind Currency Screen");
        clsUtil::SetColor(11);
        cout << setw(8) << left << "" << "__________________________________________________________________";
        cout << "__________________________________________\n";

        short Answer =1;
        string Country, CurrencyCode;

        clsUtil::SetColor(1);
        cout << "\nplease enter [1]Code Or [2]Country ? ";
        clsUtil::SetColor(3);
        cin >> Answer;

            if (Answer == 1)
            {
                clsUtil::SetColor(1);
                cout << "\nplease enter Currency Code ? ";
                clsUtil::SetColor(3);
                CurrencyCode = clsInputValidate::ReadString();
                clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
                _ShowResults(Currency);

            }
            else 
            {
                clsUtil::SetColor(1);
                cout << "\nplease enter Country ? ";
                clsUtil::SetColor(3);
                Country = clsInputValidate::ReadString();
                clsCurrency Currency = clsCurrency::FindByCountry(Country);
                 _ShowResults(Currency);

            }
         

    }



};

