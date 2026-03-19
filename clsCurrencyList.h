#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsUtil.h"

class clsCurrencyList :protected clsScreen
{
private:

    static void _PrintCurrenciesRecord(clsCurrency Currency)
    {
        clsUtil::SetColor(2);
        cout << setw(13) << left << "" << "| " << setw(27) << left << Currency.Country();
        cout << "| " << setw(14) << left << Currency.CurrencyCode();
        cout << "| " << setw(40) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();

    }

public:

    static void ShowListCurrencyScreen()
    {

        vector<clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

        _DrawScreenHeader("\t    List Currencies Screen");
        
        cout << setw(13) << left << "" << "\n\t\t\t\t\t     List Currencies List (" << vCurrency.size() << ") Currency (s).\n";
        cout << setw(13) << left << "" << "=======================================================================================";
        cout << "===============\n";
        cout << setw(13) << left << "" << "| " << left << setw(27) << "Country";
        cout << "| " << left << setw(14) << "Currency Code";
        cout << "| " << left << setw(40) << "Currency Name";
        cout << "| " << left << setw(10) << "Rate\n";

        cout << setw(8) << left << "" << "=======================================================================================";
        cout << "===============\n";

        for (clsCurrency Currency : vCurrency)
        {
            _PrintCurrenciesRecord(Currency);
            cout << endl;
        }
        clsUtil::SetColor(11);
        cout << setw(13) << left << "" << "---------------------------------------------------------------------------------------";
        cout << "--------------\n";
        cout << "\n";




    }



};
