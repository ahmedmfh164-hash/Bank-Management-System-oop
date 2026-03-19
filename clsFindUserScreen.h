#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUtil.h"

class clsFindUserScreen:protected clsScreen
{
private:

    static void _PrintUser(clsUser User)
    {
        clsUtil::SetColor(2);
        cout << "\n================================================\n";
        cout << "\n\tThe User Info : \n";
        cout << "\n================================================\n";

        cout << "\nFirstName  : " << User.FirstName;
        cout << "\nLastName   : " << User.LastName;
        cout << "\nFullName   : " << User.FullName();
        cout << "\nEmail      : " << User.Email;
        cout << "\nPhone      : " << User.Phone;
        cout << "\nUsername   : " << User.UserName;
        cout << "\nPassword   : " << User.Password;
        cout << "\nPermissions: " << User.Permissions;
        cout << "\n------------------------------------------------\n";

    }

public:

    static void ShowFindUserScreen()
    {

        _DrawScreenHeader("\tFind User Screen");
        clsUtil::SetColor(11);
        cout << setw(8) << left << "" << "__________________________________________________________________";
        cout << "__________________________________________\n";

        string UserName= "";
        clsUtil::SetColor(1);
        cout << "\nplease enter UserName ? ";
        clsUtil::SetColor(3);
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            clsUtil::SetColor(1);
            cout << "\nUserName is not found, choose another one : ";
            clsUtil::SetColor(3);
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        if (!User.IsEmpty())
        {
            clsUtil::SetColor(1);
            cout << "\nUser Found:-)\n";
        }
        else
            cout << "\nUser Was Not Found:-(\n";

        _PrintUser(User);

    }


};

