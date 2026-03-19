#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUtil.h"

class clsAddNewUser :protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User)
    {
        clsUtil::SetColor(3);
        cout << "\nEnter FirstName : ";
        clsUtil::SetColor(3);
        User.FirstName = clsInputValidate::ReadString();

        clsUtil::SetColor(3);
        cout << "\nEnter LastName : ";
        clsUtil::SetColor(3);
        User.LastName = clsInputValidate::ReadString();

        clsUtil::SetColor(3);
        cout << "\nEnter Email : ";
        clsUtil::SetColor(3);
        User.Email = clsInputValidate::ReadString();

        clsUtil::SetColor(3);
        cout << "\nEnter Phone : ";
        clsUtil::SetColor(3);
        User.Phone = clsInputValidate::ReadString();

        clsUtil::SetColor(3);
        cout << "\nEnter Password : ";
        clsUtil::SetColor(3);
        User.Password = clsInputValidate::ReadString();

        clsUtil::SetColor(3);
        cout << "\nEnter Permissions: ";
        clsUtil::SetColor(3);
        User.Permissions = _ReadPermissionToSet();

    }

    static int _ReadPermissionToSet()
    {
        int Permission = 0;
        char Answer = 'n';

        clsUtil::SetColor(1);
        cout << "\nDo you want to give full access? y/n ? ";
        clsUtil::SetColor(3);
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            return -1;
        }
        clsUtil::SetColor(1);
        cout << "\nDo you want to give access to : \n";

        clsUtil::SetColor(1);
        cout << "\nShow Client List?y/n ? ";
        clsUtil::SetColor(3);
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enMainMenuePermissions::PlistClient;
        }
        clsUtil::SetColor(1);
        cout << "\nAdd New Client?y/n ? ";
        clsUtil::SetColor(3);
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission +=clsUser:: enMainMenuePermissions::pAddNewClient;
        }
        clsUtil::SetColor(1);
        cout << "\nDelete Client?y/n ? ";
        clsUtil::SetColor(3);
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission +=clsUser:: enMainMenuePermissions::pDeleteClient;
        }
        clsUtil::SetColor(1);
        cout << "\nUpdate Client?y/n ? ";
        clsUtil::SetColor(3);
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission +=clsUser:: enMainMenuePermissions::pUpdateClient;
        }
        clsUtil::SetColor(1);
        cout << "\nFind Client?y/n ? ";
        clsUtil::SetColor(3);
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission +=clsUser:: enMainMenuePermissions::pFindClient;
        }
        clsUtil::SetColor(1);
        cout << "\nTransactions?y/n ? ";
        clsUtil::SetColor(3);
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enMainMenuePermissions::pTranactions;
        }
        clsUtil::SetColor(1);
        cout << "\nManage Users?y/n ? ";
        clsUtil::SetColor(3);
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enMainMenuePermissions::pManageUsers;
        }
        clsUtil::SetColor(1);
        cout << "\nLogin Register?y/n ? ";
        clsUtil::SetColor(3);
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permission += clsUser::enMainMenuePermissions::pLoginRegisters;
        }

        return Permission;

    }

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


    static void ShowAddNewUsersScreen()
    {

        _DrawScreenHeader("\t Add New User Screen");

        string UserName = "";
        clsUtil::SetColor(1);
        cout << "\nPlease Enter UserName: ";
        clsUtil::SetColor(3);
        UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(UserName))
        {
            clsUtil::SetColor(1);
            cout << "\nUserName Is Already Used, Choose anther UserName : ";
            clsUtil::SetColor(3);
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
        {
            clsUtil::SetColor(1);
            cout << "\nUser Added Successfully:-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFailedEmptyObject:
        {
            cout << "\nError User was saved because it's Empty.";
            break;
        }
        case clsUser::enSaveResults::svFailedUserNameExists:
        {
            cout << "\nError User was saved because UserName is used..";
            break;
        }
        }



    }

};