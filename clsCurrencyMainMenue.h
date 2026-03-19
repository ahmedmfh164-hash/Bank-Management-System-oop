#pragma once
#include"clsScreen.h"
#include<iostream>
#include"clsInputValidate.h"
#include"clsCurrencyList.h"
#include"clsFindCurrency.h"
#include"clsUpdateRate.h"
#include"clsCurrencyCalculator.h"
#include"clsUtil.h"

class clsCurrencyMainMenue :protected clsScreen
{
private:

    enum enCurrencyMainMenueOptions
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4, MainMenue = 5
    };

    static short _ReadCurrencyMenueOption()
    {
        clsUtil::SetColor(1);
        cout << setw(37) << left << "" << "Choose what do you want to do [1 to 5] ? ";
        clsUtil::SetColor(3);
       short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5");
        return Choice;
    }

    static void _GoBackToCurrencyMainMenue()
    {
        clsUtil::SetColor(6);
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency main menue...\n";
        system("pause>0");
        ShowCurrencyMainMenueScreen();
    }

    static void _ShowListCurrenciesScreen()
    {
        clsCurrencyList::ShowListCurrencyScreen();
        _GoBackToCurrencyMainMenue();

    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrency::ShowFindCurrencyScreen();
        _GoBackToCurrencyMainMenue();
    }

    static void _ShowUpdateRateScreen()
    {
        clsUpdateRate::ShowUpdateRateScreen();
        _GoBackToCurrencyMainMenue();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
        _GoBackToCurrencyMainMenue();
    }

    static void _PerformCurrencyMainMenueOption(enCurrencyMainMenueOptions CurrencyMainMenueOptions)
    {

        switch (CurrencyMainMenueOptions)
        {

        case enCurrencyMainMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrenciesScreen();
            break;
        }
        case enCurrencyMainMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            break;
        }
        case enCurrencyMainMenueOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateRateScreen();
            break;
        }
        case enCurrencyMainMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            break;
        }
        case enCurrencyMainMenueOptions::MainMenue:
        {
            system("cls");
            
            break;
        }

        }

    }

public:

    static void ShowCurrencyMainMenueScreen()
    {

        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pCurrencies))
        {
            return ;
        }

        system("cls");
        _DrawScreenHeader("\t\tCurrency Main Menue Screen");
        clsUtil::SetColor(3);
        cout << setw(29) << left << "" << "==================================================================\n";
        cout << setw(31) << left << "" << "\t\t\tCurrency Main Menue Screen\n";
        cout << setw(29) << left << "" << "==================================================================\n";
        clsUtil::SetColor(2);
        cout << setw(35) << left << "" << "\t\t[1] List Currencies.\n";
        cout << setw(35) << left << "" << "\t\t[2] Find Currency.\n";
        cout << setw(35) << left << "" << "\t\t[3] Update Rate.\n";
        cout << setw(35) << left << "" << "\t\t[4] Currency Calculator.\n";
        cout << setw(35) << left << "" << "\t\t[5].Main Menue\n";
        clsUtil::SetColor(3);
        cout << setw(29) << left << "" << "==================================================================\n\n";

        _PerformCurrencyMainMenueOption((enCurrencyMainMenueOptions)_ReadCurrencyMenueOption());

    }

};