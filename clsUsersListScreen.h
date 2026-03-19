#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>
#include"clsUtil.h"

using namespace std;

class clsUsersListScreen :protected clsScreen
{
private:

    static void _PrintUsersRecord(clsUser User)
    {
        clsUtil::SetColor(2);
        cout << setw(26) << left << "" << "| " << setw(25) << left << User.UserName;
        cout << "| " << setw(25) << left << User.Password;
        cout << "| " << setw(10) << left << User.Permissions;

    }

public:

    static void ShowAllUsersScreen()
    {
        vector<clsUser> vUser =clsUser::GetUsersList();

        _DrawScreenHeader("\t    List Users Screen");

        
        cout << setw(25) << left << "" << "\n\t\t\t\t\t     List Users List (" << vUser.size() << ") User (s).\n";
        cout << setw(25) << left << "" << "==========================================================================\n";

        cout << setw(26) << left << "" << "| " << left << setw(25) << "Account Number";
        cout << "| " << left << setw(25) << "Password";
        cout << "| " << left << setw(10) << "Permissions\n";

        cout << setw(25) << left << "" << "==========================================================================\n";

        for (clsUser User : vUser)
        {
            _PrintUsersRecord(User);
            cout << endl;
        }
        clsUtil::SetColor(11);
        cout << setw(25) << left << "" << "--------------------------------------------------------------------------";
        cout << "\n";

    }



};

