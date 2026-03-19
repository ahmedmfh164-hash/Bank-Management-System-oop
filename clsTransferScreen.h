#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"Global.h"
#include"clsUtil.h"

class clsTransferScreen:protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		clsUtil::SetColor(2);
		cout << "\n--------------------------------------";
		cout << "\nClient Card : ";
		cout << "\n--------------------------------------";
		cout << "\nFullName       : " << Client.FullName();
		cout << "\nAccount Number : " << Client.AccountNumber();
		printf("\nAccountBalance: %.f", Client.AccountBalance);
		cout << "\n--------------------------------------\n";

	}

	static string _ReadAccountNumber(string Message)
	{
		string AccountNumber = "";

		clsUtil::SetColor(1);
		cout << Message;
		clsUtil::SetColor(3);
		 AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			clsUtil::SetColor(1);
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			clsUtil::SetColor(3);
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient Client)
	{

		double Amount = 0;
		clsUtil::SetColor(1);
		cout << "\nPlease enter transfer amount ? ";
		clsUtil::SetColor(3);
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > Client.AccountBalance)
		{
			clsUtil::SetColor(1);
			cout << "\nAmount Exceeds the available Balance, Enter amount another : ";
			clsUtil::SetColor(3);
			Amount = clsInputValidate::ReadDblNumber();

		}

		return Amount;

	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPlease enter AccountNumber to Transfer From : "));
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease enter AccountNumber to Transfer To : "));
		_PrintClient(DestinationClient);

		double Amount=_ReadAmount(SourceClient);

		clsUtil::SetColor(1);
		cout << "\nAre you sure you want to perform this transaction : ";

		clsUtil::SetColor(3);
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			SourceClient.Withdraw(Amount);
			DestinationClient.Deposit(Amount);

			clsUtil::SetColor(1);
				cout << "\nAmount Transfer Successfully.\n";
			
			printf("\nNew Balance Is : %.f \n", SourceClient.AccountBalance);
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
		clsBankClient::SaveTransferDataToFile(SourceClient, DestinationClient, Amount);
		
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);


	}


};

