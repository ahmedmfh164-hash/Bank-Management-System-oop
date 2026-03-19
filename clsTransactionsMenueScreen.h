#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsTotalBalancesScreen.h"
#include"clsDepositeScreen.h"
#include"clsWithdrawScreen.h"
#include"clsUser.h"
#include"clsTransferScreen.h"
#include"clsTransferListScreen.h"
#include"clsUtil.h"

class clsTransactionsMenueScreen  :protected clsScreen
{
private:

    enum enTransactionsMenue {
        enDeposit = 1, enWthdraw = 2,
        enTotalBalances = 3,enTransfer=4,enTransferList=5, enMainMenue = 6
    };

    static short _ReadTransactionsMenueOption()
    {
        clsUtil::SetColor(1);
        cout << setw(37) << left << "" << "Choose what do you want to do [1 to 6] ? ";
        clsUtil::SetColor(3);
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "\nEnter Number between 1 to 6 ? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
        _GoBackToTransactionsMenue();

    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
        _GoBackToTransactionsMenue();

    }

    static void  _ShowTotalBalances()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
        _GoBackToTransactionsMenue();

    }

    static void  _ShowTransfer()
    {
        clsTransferScreen::ShowTransferScreen();
        _GoBackToTransactionsMenue();

    }

    static void  _ShowTransferList()
    {
        clsTransferListScreen::ShowTransferListScreen();
        _GoBackToTransactionsMenue();

    }

    static void _GoBackToTransactionsMenue()
    {
        clsUtil::SetColor(6);
        cout << "\n\nPress any Key go back to transactions menue ...";
        system("pause>0");
        system("cls");
        ShowTransactionsMenueScreen();
    }

    static void _PerformTransactionsMenueOption(enTransactionsMenue TransactionsMenue)
    {

        switch (TransactionsMenue)
        {

        case enTransactionsMenue::enDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            break;
        }

        case enTransactionsMenue::enWthdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            break;
        }

        case enTransactionsMenue::enTotalBalances:
        {
            system("cls");
            _ShowTotalBalances();
            break;
        }

        case enTransactionsMenue::enTransfer:
        {
            system("cls");
            _ShowTransfer();
            break;
        }

        case enTransactionsMenue::enTransferList:
        {
            system("cls");
            _ShowTransferList();
            break;
        }

        case enTransactionsMenue::enMainMenue:
        {
            
        }

        }
    }


public:

	static void ShowTransactionsMenueScreen()
    {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pTranactions))
        {
            return;
        }

        _DrawScreenHeader("\t Transactions Menue Screen");

        clsUtil::SetColor(3);
        cout << setw(31) << left << "" << "==============================================================\n";
        cout << setw(31) << left << "" << "\t\t\tTransactions Menue\n";
        cout << setw(31) << left << "" << "==============================================================\n";
        clsUtil::SetColor(2);
        cout << setw(33) << left << "" << "\t\t[1] Deposit.\n";
        cout << setw(33) << left << "" << "\t\t[2] Withdraw.\n";
        cout << setw(33) << left << "" << "\t\t[3] Total Balances.\n";
        cout << setw(33) << left << "" << "\t\t[4] Transfer.\n";
        cout << setw(33) << left << "" << "\t\t[5] Transfer List.\n";
        cout << setw(33) << left << "" << "\t\t[6] Main Menue.\n";
        clsUtil::SetColor(3);
        cout << setw(31) << left << "" << "==============================================================\n\n";

        _PerformTransactionsMenueOption((enTransactionsMenue)_ReadTransactionsMenueOption());

    }



};

