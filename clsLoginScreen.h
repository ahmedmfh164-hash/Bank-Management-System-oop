#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include<iostream>
#include"clsMainScreen.h"
#include"Global.h"
#include"clsUtil.h"

class clsLoginScreen:protected clsScreen
{
    private:

        static bool _Login()
        {
            bool LoginFailed = false;
            short TrialsFailed = 3; 

            string Username, Password;
            do
            {
                clsUtil::SetColor(1);
                if (LoginFailed)
                {
                    TrialsFailed--;
                    cout << "\nInvalid Username/Password!\n";
                    cout << "You Have " << TrialsFailed << " Trials To Logic .\n";
                    if (TrialsFailed == 0)
                    {
                        cout << "\nYour are Locked after 3 failed trails.\n";
                        return false;
                    }
                }
                cout << "\nEnter Username ? ";
                clsUtil::SetColor(3);
                cin >> Username;
                clsUtil::SetColor(1);
                cout << "\nEnter Password ? ";
                clsUtil::SetColor(3);
                cin >> Password;

                CurrentUser = clsUser::Find(Username, Password);
                
                LoginFailed = CurrentUser.IsEmpty();
            } while (LoginFailed);

            CurrentUser.RegisterLogin();
                clsMainScreen::ShowMainMenueScreen();
                return true;
        }

public:

    static bool ShowLoginScreen()
    {
     
            system("cls");
            _DrawScreenHeader("\t\tLogic Screen");
            return _Login();
          
    }




};

