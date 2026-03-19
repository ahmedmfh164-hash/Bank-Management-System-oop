#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUtil.h"

class clsDeleteUserScreen:protected clsScreen
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

    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\tDelete User Screen");
        clsUtil::SetColor(11);
        cout << setw(8) << left << "" << "__________________________________________________________________";
        cout << "__________________________________________\n";

        string UserName = "";
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
        _PrintUser(User);

        clsUtil::SetColor(1);
        cout << "\nAre you sure you want to delete this User ? y/n ? ";
        clsUtil::SetColor(3);
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (User.Delete())
            {
                clsUtil::SetColor(1);
                cout << "\nUser Deleted Successfully:-)\n";
                _PrintUser(User);

            }

        }

    }



};

