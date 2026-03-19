#pragma once
#include"clsDate.h"
#include<fstream>
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsString.h"
#include<vector>
#include"clsUtil.h"

class clsLoginRegister:protected clsScreen
{
private:

	
	static void _PrintLoginsRecord(clsUser::stLoginRegister Login)
	{
		clsUtil::SetColor(2);
		cout << setw(15) << left << "" << "| " << setw(25) << left << Login.DateTime;
		cout << "| " << setw(22) << left << Login.UserName;
		cout << "| " << setw(21) << left << Login.Password;
		cout << "| " << setw(10) << left << Login.Permissions;

	}

public:

	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::enMainMenuePermissions::pLoginRegisters))
		{
			return;
		}

		vector<clsUser::stLoginRegister>vLogin = clsUser::GetRegisterList();

		string Title = "\t Login Register List Screen";
		string SubTitle = "\t\t (" + to_string(vLogin.size()) + ") Record (s).";
		
		_DrawScreenHeader(Title,SubTitle);

		clsUtil::SetColor(3);
		cout << setw(14) << left << "" << "================================================================================================\n";

		cout << setw(15) << left << "" << "| " << left << setw(25) << "Date Time";
		cout << "| " << left << setw(22) << "UserName";
		cout << "| " << left << setw(21) << "Password";
		cout << "| " << left << setw(10) << "Permissions\n";

		cout << setw(14) << left << "" << "================================================================================================\n";


		if (vLogin.size() == 0)
		{
			cout << "\n\t\t\tNo LoginRegister Available In the System!\n";
		}
		else
		for (clsUser::stLoginRegister Login : vLogin)
		{
			_PrintLoginsRecord(Login);
			cout << endl;
		}

		cout << setw(14) << left << "" << "------------------------------------------------------------------------------------------------";
		cout << "\n";




	}



};

