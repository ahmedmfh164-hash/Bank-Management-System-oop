#pragma once
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUtil.h"

class clsTransferListScreen:protected clsScreen
{
private:

    static void _PrintTransferRecord(clsBankClient::stTransfer Transfer)
    {
         clsUtil::SetColor(2);
  cout << setw(3) << left << "" << "| " << setw(20) << left << Transfer.DateTime;
  cout <<"| "<< setw(15) << left << Transfer.AccountNumberFrom;
  cout << "| " << left << setw(16) << Transfer.AccountBalanceFrom;
  cout << "| " << setw(14) << left << Transfer.AccountNumberTo;
  cout << "| " << left << setw(16) << Transfer.AccountBalanceTo;
  cout << "| " << left << setw(12) <<Transfer.Amount;
  cout <<"| "<< left << setw(8) << CurrentUser.UserName;
    }

public:

	static void ShowTransferListScreen()
	{

        vector<clsBankClient::stTransfer>vTransfer = clsBankClient::GetTransfersList();

        string Title = "\t    Transfer List Screen";
        string SubTitle = "\t      (" + to_string(vTransfer.size()) + ") Transfers (s) ";

        _DrawScreenHeader(Title, SubTitle);

       cout << setw(3) << left << "" << "=================================================";
cout << "=====================================================================\n";
cout << setw(3) << left << "" << "| " << left << setw(20) <<"Date Time" <<"| "<<
    left << setw(15) << "Account Number1";
cout << "| " << left << setw(16) << "Account Balance1";
cout << "| " << left << setw(14) << "AccountNumber2";
cout << "| " << left << setw(16) << "Account Balance2";
cout << "| " << left << setw(12) << "Amount";
cout << "| " << left << setw(13) << "User Name";
cout << "\n" << setw(3) << left << "" << "=================================================";
cout << "=====================================================================\n";

if (vTransfer.size() == 0)
{
    cout << "\n\t\t\tNo Transfers Available In the System!\n";
}
else
    for (clsBankClient::stTransfer Transfer : vTransfer)
    {
        _PrintTransferRecord(Transfer);
        cout << endl;
    }
clsUtil::SetColor(11);
cout << setw(3) << left << "" << "-----------------------------------------------------";
cout << "-----------------------------------------------------------------\n";

        cout << "\n";


	}


};

