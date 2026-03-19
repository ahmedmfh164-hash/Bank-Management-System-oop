#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>
#include"clsUtil.h"

using namespace std;

class clsClientListScreen :protected clsScreen
{
private:

    static void PrintClientRecord(clsBankClient Client)
    {
        clsUtil::SetColor(2);
        cout << setw(8) << left << "" << "| " << setw(14) << left << Client.AccountNumber();
        cout << "| " << setw(15) << left << Client.FullName();
        cout << "| " << setw(13) << left << Client.PinCode;
        cout << "| " << setw(24) << left << Client.Email;
        cout << "| " << setw(15) << left << Client.Phone;
         printf("| %.f",Client.AccountBalance);
    }

public:

    static void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::PlistClient))
        {
            return;
        }

        vector<clsBankClient> vClient = clsBankClient::GetClientsList();

        string Title = "\t    Client List Screen";
        string SubTitle = "\t      (" + to_string(vClient.size()) + ") Clients (s) ";

        _DrawScreenHeader(Title, SubTitle);

        cout <<"\n"<< setw(7) << left << "" << "=============================================================";
        cout << "===================================================\n";
        cout << setw(8)<<left<<"" << "| " << left << setw(14) << "Account Number";
        cout <<  "| " << left << setw(15) << "Client Name";
        cout << "| " << left << setw(13) << "Pin Code";
        cout <<  "| " << left << setw(24) << "Email";
        cout <<  "| " << left << setw(15) << "Phone";
        cout <<  "| " << left << setw(15) << "Balance";
        cout << "\n"<<setw(7) << left << "" << "=============================================================";
        cout << "===================================================\n";

        if (vClient.size() == 0)
        {
            cout << "\n\t\t\tNo Clients Available In the System!\n";
        }
        else
            for (clsBankClient Client : vClient)
            {
                PrintClientRecord(Client);
                cout << endl;
            }
        clsUtil::SetColor(11);
        cout << setw(7)<<left<<"" << "------------------------------------------------------------";
        cout << setw(8) << "----------------------------------------------------\n";

        cout << "\n";

    }



};

