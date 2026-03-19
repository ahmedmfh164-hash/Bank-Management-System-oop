#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"

class clsFindClientScreen  :protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        clsUtil::SetColor(2);
        cout << "\n--------------------------------------";
        cout << "\nClient Card : ";
        cout << "\n--------------------------------------";
        cout << "\nFirstName      : " << Client.FirstName;
        cout << "\nLastName       : " << Client.LastName;
        cout << "\nFullName       : " << Client.FullName();
        cout << "\nEmail          : " << Client.Email;
        cout << "\nPhone          : " << Client.Phone;
        cout << "\nAccount Number : " << Client.AccountNumber();
        cout << "\nPassword       : " << Client.PinCode;
        printf("\nAccountBalance: %.f", Client.AccountBalance);
        cout << "\n--------------------------------------";

    }

public:

    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pFindClient))
        {
            return;
        }

        _DrawScreenHeader("\tFind Client Screen");

        cout << setw(8) << left << "" << "__________________________________________________________________";
        cout << "__________________________________________\n";

        string AccountNumber = "";
        clsUtil::SetColor(1);
        cout << "\nplease enter client Account Number ? ";
        clsUtil::SetColor(3);
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            clsUtil::SetColor(1);
            cout << "\nAccount Number is not found, choose another one : ";
            clsUtil::SetColor(3);
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found:-)\n";
        }
        else
            cout << "\nClient Was Not Found:-(\n";

        _PrintClient(Client1);

    }



};

