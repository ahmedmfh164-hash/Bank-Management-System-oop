#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"

class clsWithdrawScreen	:protected clsScreen
{
private:
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

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		clsUtil::SetColor(1);
		cout << "\nPlease enter AccountNumber ? ";
		clsUtil::SetColor(3);
		cin >> AccountNumber;

		return AccountNumber;
	}

public:

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t\tWithdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			clsUtil::SetColor(1);
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			clsUtil::SetColor(3);
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		double Amount = 0;
		clsUtil::SetColor(1);
		cout << "\nPlease enter withdraw amount ? ";
		clsUtil::SetColor(3);
		Amount = clsInputValidate::ReadDblNumber();

		clsUtil::SetColor(1);
		cout << "\nAre you sure you want to perform this transaction ? ";
		clsUtil::SetColor(3);
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Client.Withdraw(Amount);

			clsUtil::SetColor(1);
			cout << "\nAmount Withdraw Successfully.\n";
			printf("\nNew Balance Is : %.f", Client.AccountBalance);
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}


	}

};

