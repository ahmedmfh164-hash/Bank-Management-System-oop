#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsMenueScreen.h"
#include"clsManageUsersScreen.h"
#include"Global.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyMainMenue.h"
#include"clsUtil.h"

using namespace std;

class clsMainScreen :protected clsScreen
{
private:
    enum enMainMenueOptions
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eTransactionMenue = 6, eManageUsers = 7, enLoginRegisters = 8,eCurrencies=9, eLogout = 10
    };

    static short _ReadTransactionsMenueOption()
    {
        clsUtil::SetColor(1);
        cout << setw(37) << left << "" << "Choose what do you want to do [1 to 10] ? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10");
        return Choice;
    }

    static void _GoBackToMainMenue()
    {
        clsUtil::SetColor(6);
        cout << setw(37) << left << "" << "\n\tPress any key to go back to main menue...\n";
        system("pause>0");
        ShowMainMenueScreen();
    }

    static void _GoToMainMenue()
    {
        ShowMainMenueScreen();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
        _GoBackToMainMenue();

    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClient();
        _GoBackToMainMenue();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
        _GoBackToMainMenue();

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
        _GoBackToMainMenue();


    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
        _GoBackToMainMenue();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsMenueScreen::ShowTransactionsMenueScreen();
        _GoToMainMenue();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static void _ShowManageUsersScreen()
    {
        clsManageUsersScreen::ShowManageUsersScreen();
        _GoToMainMenue();
    }

    static void _ShowLoginRegisters()
    {
        clsLoginRegister::ShowLoginRegisterScreen();
        _GoBackToMainMenue();
    }

    static void _ShowCurrencyMainMenue()
    {
        clsCurrencyMainMenue::ShowCurrencyMainMenueScreen();
        _GoToMainMenue();
    }

    static void _PerformMainMenueOption(enMainMenueOptions MainMenueOption)
    {

        switch (MainMenueOption)
        {

        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
        {
                system("cls");
                _ShowAddNewClientsScreen();
            break;
        }

        case enMainMenueOptions::eDeleteClient:
        {
                system("cls");
                _ShowDeleteClientScreen();
            break;
        }

        case enMainMenueOptions::eUpdateClient:
        {
                system("cls");
                _ShowUpdateClientScreen();
            break;
        }

        case enMainMenueOptions::eFindClient:
        {
                system("cls");
                _ShowFindClientScreen();
            break;
        }

        case enMainMenueOptions::eTransactionMenue:
        {
                system("cls");
                _ShowTransactionsMenue();
            break;
        }

        case enMainMenueOptions::eManageUsers:
        {
                system("cls");
                _ShowManageUsersScreen();
            break;
        }


        case enMainMenueOptions::enLoginRegisters:
            system("cls");
            _ShowLoginRegisters();
            break;

        case enMainMenueOptions::eCurrencies:
            system("cls");
            _ShowCurrencyMainMenue();
            break;

        case enMainMenueOptions::eLogout:
        {
            system("cls");
            _Logout();
            break;
        }

        }

    }

public:

    static void ShowMainMenueScreen()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(29) << left << "" << "==================================================================\n";
        cout << setw(31) << left << "" << "\t\t\t     Main Menue Screen\n";
        cout << setw(29) << left << "" << "==================================================================\n";
        clsUtil::SetColor(2);
        cout << setw(35) << left << "" << "\t\t[1] Show All Clients List.\n";
        cout << setw(35) << left << "" << "\t\t[2] Add New Client.\n";
        cout << setw(35) << left << "" << "\t\t[3] Delete Client.\n";
        cout << setw(35) << left << "" << "\t\t[4] Update Client Info.\n";
        cout << setw(35) << left << "" << "\t\t[5] Find Client.\n";
        cout << setw(35) << left << "" << "\t\t[6] Transactions.\n";
        cout << setw(35) << left << "" << "\t\t[7] Manage Users.\n";
        cout << setw(35) << left << "" << "\t\t[8] Login Registers.\n";
        cout << setw(35) << left << "" << "\t\t[9] Currencies.\n";
        cout << setw(35) << left << "" << "\t\t[10] Logout.\n";
        clsUtil::SetColor(11);
        cout << setw(29) << left << "" << "==================================================================\n\n";

        _PerformMainMenueOption((enMainMenueOptions)_ReadTransactionsMenueOption());


    }





};