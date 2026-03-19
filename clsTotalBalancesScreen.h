#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"

class clsTotalBalancesScreen :protected clsScreen
{
private:

    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        clsUtil::SetColor(2);
        cout << setw(22) << left << "" << "| " << setw(20) << left << Client.AccountNumber();
        cout << "| " << setw(30) << left << Client.FullName();
        printf("| %.f", Client.AccountBalance);
    }

public:

    static void ShowTotalBalances()
    {
        _DrawScreenHeader("\tTotal Balances Screen");

        vector<clsBankClient> vClient = clsBankClient::GetClientsList();

        cout <<"\n" << setw(9) << left << "" << "\t\t\t\t\tClient List (" << vClient.size() << ") Client (s).\n";
        cout << setw(21) << left << "" << "=================================================================================\n";
        cout << setw(22) << left << "" << "| " << left << setw(20) << "Account Number";
        cout <<  "| " << left << setw(30) << "Client Name";
        printf("| Account Balance\n");
        cout << setw(21) << left << "" << "=================================================================================\n";

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClient.size() == 0)
        {
            cout << "\n\t\t\tNo Clients Available In the System!\n";
        }
        else
            for (clsBankClient Client : vClient)
            {
                _PrintClientRecordBalanceLine(Client);
                cout << endl;
            }
        cout << setw(21) << left << "" << "---------------------------------------";
        cout << "-------------------------------------------\n";
        cout << setw(27) << left << "";
        printf("\t\t\tTotal Balances = %.f \n", TotalBalances);
        cout << setw(22) << left << "" << "\t(" << clsUtil::NumberToText(TotalBalances) << ")\n";
        cout << setw(21) << left << "" << "---------------------------------------";
        cout << "-------------------------------------------\n";
        cout << "\n";

    }




};

