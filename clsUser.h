#pragma once
#include"clsPerson.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h"
#include"clsDate.h"
#include"clsUtil.h"

class clsUser :public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;



    string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkForDelete = false;

	static clsUser _ConvertLineToUserObject(string Line, string Separator = "#//#")
	{
		vector<string>vUserData;
		vUserData = clsString::Split(Line, Separator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5],3), stoi(vUserData[6]));

	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertUserObjectToLine(clsUser User, string sperator = "#//#")
	{
		string stUserRecord = "";

		stUserRecord += User.FirstName + sperator;
		stUserRecord += User.LastName + sperator;
		stUserRecord += User.Email + sperator;
		stUserRecord += User.Phone + sperator;
		stUserRecord += User.UserName + sperator;
		stUserRecord += clsUtil::EncryptText(User.Password,3) + sperator;
		stUserRecord += to_string(User.Permissions);

		return stUserRecord;

	}

	struct stLoginRegister;

	static stLoginRegister ConvertLineToLogin(string Line, string Separator = "#//#")
	{
		stLoginRegister LoginRegister;

		vector<string>vLoginData = clsString::Split(Line, Separator);

		LoginRegister.DateTime = vLoginData[0];
		LoginRegister.UserName = vLoginData[1];
		LoginRegister.Password = clsUtil::EncryptText(vLoginData[2],3);
		LoginRegister.Permissions = stoi(vLoginData[3]);

		return LoginRegister;
	}


	 string _PrePareLoginRecord( string sperator = "#//#")
	{
		string LoginRecord = "";

		LoginRecord += clsDate::GetSystemDateTimeString() + sperator;
		LoginRecord += UserName + sperator;
		LoginRecord += clsUtil::DecryptText(Password,3)+sperator;
		LoginRecord += to_string(Permissions);

		return LoginRecord;

	}

	static vector<clsUser> _LoadUsersDataFromFile()
	{
		vector<clsUser>vUser;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUser.push_back(User);
			}

			MyFile.close();

		}

		return vUser;
	}

	static void _SaveUserDataToFile(vector<clsUser> vUser)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overWrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsUser& U : vUser)
			{
				if (U._MarkForDelete == false)
				{
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;

				}
			}
			MyFile.close();
		}

	}

	void _Update()
	{
		vector<clsUser>_vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == _UserName)
			{
				U = *this;
				break;
			}
		}
		_SaveUserDataToFile(_vUsers);

	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}

	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}


public:


	enum enMainMenuePermissions {
		eAll = -1, PlistClient = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
		,pLoginRegisters = 128,pCurrencies=256
	};



	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string UserName, string Password, int Permissions)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool MarkForDelete()
	{
		return _MarkForDelete;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

    string GetUserName()
	{
		return _UserName;
	}

	__declspec(property(put = SetUserName, get = GetUserName))string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(put = SetPassword, get = GetPassword))string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(put = SetPermissions, get = GetPermissions))int Permissions;

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}

			}
			MyFile.close();
		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}

			}
			MyFile.close();
		}

		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	static bool IsUserExist(string UserName, string Password)
	{
		clsUser User = clsUser::Find(UserName, Password);
		return (!User.IsEmpty());
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedUserNameExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
				return enSaveResults::svFailedEmptyObject;
			break;
		}

		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}

		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFailedUserNameExists;
			}
			else
			{
				_AddNew();

				//we need to set the mode to update after add new
				_Mode = enMode::UpdateMode;

			}
			break;
		}

		}
		return enSaveResults::svSucceeded;

	}

	static clsUser GetNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete()
	{
		vector<clsUser>_vUser;
		_vUser = _LoadUsersDataFromFile();

		for (clsUser& U : _vUser)
		{
			if (U.UserName == _UserName)
			{
				U._MarkForDelete = true;
				break;
			}

		}
		_SaveUserDataToFile(_vUser);

		*this = _GetEmptyUserObject();
		return true;

	}

	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	 bool CheckAccessPermission(enMainMenuePermissions Permission)
	{
		if (this->Permissions == enMainMenuePermissions::eAll)
			return true;

		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;
	}

	 static struct stLoginRegister
	 {
		 string DateTime;
	     string UserName;
		 string Password;
		 int Permissions;
	 };

	 void RegisterLogin()
	 {
		 string stDateLine = _PrePareLoginRecord();

			 fstream MyFile;
			 MyFile.open("RegisterLogin.txt", ios::out|ios::app);//overWrite

			 if (MyFile.is_open())
			 {
						 MyFile << stDateLine << endl;
				 
				 MyFile.close();
			 }

		 }

	 static vector<stLoginRegister> GetRegisterList()
	 {
		 vector<stLoginRegister>vLoginRegister;
		 fstream MyFile;

		 MyFile.open("RegisterLogin.txt", ios::in);

		 if (MyFile.is_open())
		 {
			 string Line;
			 stLoginRegister Login;

			 while (getline(MyFile, Line))
			 {
				 Login = ConvertLineToLogin(Line);

				 vLoginRegister.push_back(Login);
			 }

			 MyFile.close();

		 }

		 return vLoginRegister;
	 }

};


