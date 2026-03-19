#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUtil.h"

class clsAddNewClientScreen	:protected clsScreen
{

private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        clsUtil::SetColor(1);
        cout << "\nEnter FirstName : ";
        clsUtil::SetColor(3);
        Client.FirstName = clsInputValidate::ReadString();

        clsUtil::SetColor(1);
        cout << "\nEnter LastName : ";
        clsUtil::SetColor(3);
        Client.LastName = clsInputValidate::ReadString();

        clsUtil::SetColor(1);
        cout << "\nEnter Email : ";
        clsUtil::SetColor(3);
        Client.Email = clsInputValidate::ReadString();

        clsUtil::SetColor(1);
        cout << "\nEnter Phone : ";
        clsUtil::SetColor(3);
        Client.Phone = clsInputValidate::ReadString();

        clsUtil::SetColor(1);
        cout << "\nEnter PinCode : ";
        clsUtil::SetColor(3);
        Client.PinCode = clsInputValidate::ReadString();

        clsUtil::SetColor(1);
        cout << "\nEnter Account Balance: ";
        clsUtil::SetColor(3);
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();

    }

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
        cout << "\nAccount Balance: " << Client.AccountBalance;
        cout << "\n--------------------------------------";

    }

public:

   static void ShowAddNewClient()
    {
       if (!CheckAccessRights(clsUser::enMainMenuePermissions::pAddNewClient))
       {
           return;
       }

       _DrawScreenHeader("\tAdd New Client Screen");

        string AccountNumber = "";

        cout <<setw(8)<< left<<""<<"__________________________________________________________________";
        cout << "__________________________________________\n";

        clsUtil::SetColor(1);
        cout << "\nplease Enter Account Number : ";
        clsUtil::SetColor(3);
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            clsUtil::SetColor(1);
            cout << "\nAccount Number Is Already User, Choose another one : ";
            clsUtil::SetColor(3);
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Added Successfully :_)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFailedEmptyObject:
        {
            cout << "\nError Account was not saved because it's Empty.";
            break;
        }
        case clsBankClient::enSaveResults::svFailedAccountNumberExists:
        {
            cout << "\nFailed Account Number Is Already User.";
            break;
        }
        }

    }



};

