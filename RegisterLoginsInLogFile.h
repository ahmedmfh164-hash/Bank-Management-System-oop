#pragma once
#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include"clsUser.h"
#include"clsDate.h"

using namespace std;

class clsRegister:public clsUser
{
private:

	string _Date;
	string _Time;

	static string _ConvertUserObjectToLine(clsRegister User, string sperator = "#//#")
	{


		string stUserRecord = "";

		stUserRecord += User._Date + sperator;
		stUserRecord += User._Time + sperator;
		stUserRecord += User.UserName + sperator;
		stUserRecord += User.Password + sperator;
		stUserRecord += to_string(User.Permissions);

		return stUserRecord;
	}

	static void _SaveUserDataToLogFile(vector<clsRegister> vRegister)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overWrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsRegister& R: vRegister)
			{
					DataLine = _ConvertUserObjectToLine(R);
					MyFile << DataLine << endl;
			}
			MyFile.close();
		}

	}

public:


};

