#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"Global.h"
#include"clsDate.h"
#include"clsUtil.h"

using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		clsUtil::SetColor(3);
		cout << setw(29) << left << "" << "==================================================================\n";
		cout << "\n\t\t\t\t\t       " << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t  " << SubTitle;
		}
		cout <<"\n" << setw(29) << left << "" << "==================================================================\n\n";

		clsDate Date;
		clsUtil::SetColor(11);
		cout<< setw(31) << left <<""<< "User Name  : " << CurrentUser.UserName<<"\n";
		cout << setw(31) << left << "" << "Date Today : " << Date.DayShortName(Date.Day, Date.Month, Date.Year)
			<< ", " << Date.MonthShortName(Date.Month) << ", "
			<< Date.DateToString(Date.GetSystemDate())<< "\n\n";


	}

	static bool CheckAccessRights(clsUser::enMainMenuePermissions Permissions)
	{
		if (!CurrentUser.CheckAccessPermission(Permissions))
		{
			clsUtil::SetColor(3);
			cout << setw(28) << left << "" << "===========================================================\n";
			cout << setw(33) << left << "" << "\t\t  Access Denied,\n";
			cout << setw(31) << left << "" << "\t       You don't Have Permission To Do this,\n";
			cout << setw(31) << left << "" << "\t\t    Please Contact your Admin.\n";
			cout << setw(28) << left << "" << "===========================================================\n";
			return false;
		}
		else
			return true;

	}


};

