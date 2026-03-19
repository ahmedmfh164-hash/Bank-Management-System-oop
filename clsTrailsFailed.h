#pragma once
#include"Global.h"
#include"clsUser.h"

class clsTrailsFailed
{
private:

	static void _End()
	{
		CurrentUser = clsUser::Find("", "");
		system("cls");
		system("pause>0");
	}

public:

	static void ShowEnd()
	{
		_End();
	}

};

