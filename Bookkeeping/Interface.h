#pragma once
#include"Header.h"



class Interface {
public:
	Interface() {};
	~Interface() {};	
	static void SignMenu();
	static void ManagementAccs(vector<Account>& accs);
	static void AccountMenu(Account& acc);

	template<typename T>
	static void TransMenu(MyRing<T>& trans, Account& acc,int type);

	static void coutDeposit();
	static void coutIncome();
	static void coutExpenses();
	static void BankAccMenu(Account& acc);

	template<typename T>
	static void viewMenu(MyRing<T>& trans, int type);

	static void CurrencyMenu(Account& acc);
};

//#include"Interface.inl"