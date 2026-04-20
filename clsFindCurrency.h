#pragma once
#include <limits>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsString.h"

class clsFindCurrency:protected clsScreen
{
private:

    static short _ReadOption()
    {
        short Number;

        while (true)
        {
            clsUtil::SetColor(1);
            cout << "\nplease enter [1]Code Or [2]Country ? ";
            clsUtil::SetColor(3);
            cin >> Number;

            if (!cin.fail() && Number >= 1 && Number <= 2)
            {
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                return Number;
            }

            cin.clear();
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');

            clsUtil::SetColor(4);
            cout << "\nInvalid Entry! Try Again: ";
            clsUtil::SetColor(3);
        }
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

        string Country, CurrencyCode;

        short Answer = _ReadOption();


            if (Answer==1)
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
         
            char again = 'n';
            clsUtil::SetColor(1);
            cout << "\nAre you want to find another Currency ? y/n ? ";
            clsUtil::SetColor(3);
            cin >> again;

            if (again == 'y' || again == 'Y')
            {
                system("cls");
                ShowFindCurrencyScreen();
            }


    }



};

