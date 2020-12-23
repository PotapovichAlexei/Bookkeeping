#pragma once

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include <vector>
#include <time.h>
#include <ctime>
#include <sstream>
#include <Windows.h>
using namespace std;

#include "Account.h"
#include "MyRing.h"
#include "Exception.h"
#include "Date.h"
#include "Interface.h"


#include "Currency.h"
#include "BankAccount.h"

#include "Transaction.h"
#include "Expenses.h"
#include "Income.h"
#include "OtherIncome.h"
#include "Deposit.h"

#include "File.h"
#include "BinaryFile.h"
#include "TextFile.h"
#include "Algorithms.h"

#define ACCOUNT "Accounts.bin"
#define OTHERINCOME "OtherIncome.txt"

#define DEPOSIT "Deposit.txt"

#define EXPENSES "Expenses.txt"
#define BANKACCOUNT "BankAccount.txt"
#define CURR "Currency.txt"

//#define PEROTHERINCOME "PeriodicOtherIncome.txt"
//#define PERDEPOSIT "PeriodicDeposit.txt"
//#define PEREXPENSES "PeriodicExpenses.txt"
//#define TRANSACTIONS "Accounts.bin"
//using namespace std;