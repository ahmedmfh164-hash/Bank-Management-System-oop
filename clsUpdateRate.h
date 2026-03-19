#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
#include<iostream>
#include"clsInputValidate.h"
#include"clsUtil.h"

class clsUpdateRate :protected clsScreen
{
private:

    static float _ReadRate()
    {
        clsUtil::SetColor(1);
        cout << "\nEnter New Rate: ";
        float NewRate = 0;
        clsUtil::SetColor(3);
        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
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

public:

    static void ShowUpdateRateScreen()
    {
        _DrawScreenHeader("\tUpdate Rate Screen");

        clsUtil::SetColor(11);
        cout << setw(8) << left << "" << "__________________________________________________________________";
        cout << "__________________________________________\n";

        string CurrencyCode="";
        clsUtil::SetColor(1);
            cout << "\nplease enter Currency Code ? ";
            clsUtil::SetColor(3);
            CurrencyCode = clsInputValidate::ReadString();

            while (!clsCurrency::IsCurrencyExist(CurrencyCode))
            {
                clsUtil::SetColor(1);
                cout << "\nCurrency Code is not found, choose another one : ";
                clsUtil::SetColor(3);
                CurrencyCode = clsInputValidate::ReadString();
            }

            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

            _PrintCurrency(Currency);
            clsUtil::SetColor(1);
            cout << "\nAre You Sure want to update the rate this Currency ? y/n ? ";
            clsUtil::SetColor(3);
            char Answer = 'n';
            cin >> Answer;

            if (Answer == 'y' || Answer == 'Y')
            {
                clsUtil::SetColor(1);
                cout << "\n\nUpdate Currency Rate : ";
                cout << "\n_________________________\n";

                Currency.UpdateRate(_ReadRate());

                cout << "\nCurrency Rate Update Successfully :-)\n";
                _PrintCurrency(Currency);

            }

    }




};

