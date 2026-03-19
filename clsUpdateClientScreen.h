#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"

class clsUpdateClientScreen	 :protected clsScreen
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
        printf("\nAccountBalance: %.f", Client.AccountBalance);
        cout << "\n--------------------------------------";

    }

public:

    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pUpdateClient))
        {
            return;
        }

        _DrawScreenHeader("\tUpdate Client Screen");

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
        _PrintClient(Client1);

        clsUtil::SetColor(3);
        cout << "\n\nUpdate Client Info : ";
        cout << "\n---------------------------\n";
        _ReadClientInfo(Client1);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClient(Client1);
            break;
        }
        case clsBankClient::enSaveResults::svFailedEmptyObject:
        {
            clsUtil::SetColor(1);
            cout << "\nError account was not saved because it's Empty";
            break;
        }

        }

    }




};

