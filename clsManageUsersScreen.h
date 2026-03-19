#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUsersListScreen.h"
#include"clsAddNewUser.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
#include"clsUser.h"
#include"clsUtil.h"

class clsManageUsersScreen :protected clsScreen
{
private:

    enum enManageUsersMenue {
        enListUsers = 1, enAddNewUsers = 2, enDeleteUsers = 3,
        enUpdateUsers = 4, enFindUsers = 5,enMainMenueScreen = 6
    };

    static short _ReadManageUsersMenueOption()
    {
        clsUtil::SetColor(1);
        cout <<"\n"<< setw(37) << left << "" << "Choose what do you want to do [1 to 7] ? ";
        clsUtil::SetColor(3);
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 7, "\nEnter Number between 1 to 7 ? ");
        return Choice;
    }

    static void _GoBackToManageUsersMenue()
    {
        clsUtil::SetColor(6);
        cout << "\n\nPress any Key go back to Users menue ...";
        system("pause>0");
        system("cls");
        ShowManageUsersScreen();

    }

    static void _ShowAllUsersScreen()
    {
        clsUsersListScreen::ShowAllUsersScreen();
        _GoBackToManageUsersMenue();

    }

    static void _ShowAddNewUsersScreen()
    {
        clsAddNewUser::ShowAddNewUsersScreen();
        _GoBackToManageUsersMenue();

    }

    static void _ShowDeleteUsersScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
        _GoBackToManageUsersMenue();

    }

    static void  _ShowUpdateUsersScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
        _GoBackToManageUsersMenue();

    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
        _GoBackToManageUsersMenue();

    }

    static void _PerformManageUsersMenue(enManageUsersMenue ManageUserMenue)
    {

        switch (ManageUserMenue)
        {

        case enManageUsersMenue::enListUsers:
            system("cls");
            _ShowAllUsersScreen();
            break;

        case enManageUsersMenue::enAddNewUsers:
            system("cls");
            _ShowAddNewUsersScreen();
            break;

        case enManageUsersMenue::enDeleteUsers:
            system("cls");
            _ShowDeleteUsersScreen();
            break;

        case enManageUsersMenue::enUpdateUsers:
            system("cls");
            _ShowUpdateUsersScreen();
            break;

        case enManageUsersMenue::enFindUsers:
            system("cls");
            _ShowFindUserScreen();
            break;

        case enManageUsersMenue::enMainMenueScreen:
            system("cls");

        }

    }

public:

    static void ShowManageUsersScreen()
    {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pManageUsers))
        {
            return;
        }

        _DrawScreenHeader("\t     Manage Users Menue \n");
        clsUtil::SetColor(3);
        cout << setw(29) << left << "" << "==================================================================\n";
        cout << setw(29) << left << "" << "\t\t\tManage Users Menue Screen\n";
        cout << setw(29) << left << "" << "==================================================================\n";
        clsUtil::SetColor(2);
        cout << setw(29) << left << "" << "\t\t\t  [1] List Users.\n";
        cout << setw(29) << left << "" << "\t\t\t  [2] Add new Users.\n";
        cout << setw(29) << left << "" << "\t\t\t  [3] Delete Users.\n";
        cout << setw(29) << left << "" << "\t\t\t  [4] Update users.\n";
        cout << setw(29) << left << "" << "\t\t\t  [5] Find Users.\n";
        cout << setw(29) << left << "" << "\t\t\t  [7] Main Menue.\n";
        clsUtil::SetColor(3);
        cout << setw(29) << left << "" << "==================================================================\n";

        _PerformManageUsersMenue((enManageUsersMenue)_ReadManageUsersMenueOption());

    }


};

