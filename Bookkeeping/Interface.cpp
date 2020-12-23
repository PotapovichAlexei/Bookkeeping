#include "Header.h"
#include <direct.h>

inline void Interface::SignMenu()
{
	vector<Account> accs;
	
	//Location
	
	_mkdir("Accounts");
	_chdir("Accounts");

	//Unloading of the accounts in the vector
	fromBinFileInVector(accs, ACCOUNT);

	Account tmp;

	int flag = 0;
	do {
		system("CLS");
		cout << "\t\t~Sign menu~ " << endl << endl;
		cout << " \t1) Sign In" << endl;
		cout << " \t2) Sign Up" << endl;
		cout << " \t3) Management of accounts" << endl;
		cout << " \t0) exit" << endl << endl;
		cout << endl << "Your choice: ";
		flag = inputInt(0, 3);

		switch (flag)
		{

		case 1:
		{
			//SignIn			
			system("CLS");
			cout << "\t\t~Sign In~ " << endl << endl;
			Account currAcc;
			if (accs.empty()) {
				cout << "Please create an account before logging in" << endl;
				system("pause");
			}
			else {

				bool f = false;
				do {
					currAcc.inputAcc();
					if (currAcc.checkValidAcc(accs)) {
						//accs.push_back(currAcc);
						//objAddInTxtFile(currAcc, ACCOUNT);
						Interface::AccountMenu(currAcc);
						f = false;
					}
					else {
						cout << "Login or password uncorrectly" << endl;
						cout << "To try again enter [1], other [0]: ";
						cin >> f;
						cout << endl;
					}

				} while (f);
			}
			break;
		}

		case 2:
		{
			//SignUp
			system("CLS");
			cout << "\t\t~Sign Up~ " << endl << endl;
			Account currAcc;
			bool f = false;
			do {
				currAcc.inputAcc();
				if (currAcc.validLogin(accs)) {
					accs.push_back(currAcc);
					objAddInTxtFile(currAcc, ACCOUNT);
					Interface::AccountMenu(currAcc);
					f = false;
				}
				else {
					cout << "This login is already taken" << endl;
					cout << "To try again enter [1], other [0]: ";
					cin >> f;
					cout << endl;
				}
				
			} while (f);			
			break;
		}

		case 3:
		{
			
			Interface::ManagementAccs(accs);
			
			break;
		}

		case 0: {
			flag = 0;
			break;
		}
		default: break;
		}

		

	} while (flag != 0);
	
	
}


inline void Interface::ManagementAccs(vector<Account>& accs)
{
	int flag = 0, index = 0;
	do {
		system("CLS");
		
		cout << "\t\t~Management of Accounts~ " << endl << endl;
		for (int i = 0; i < 20; i++)
			cout << "_";
		cout << endl;
		cout << "#  |" << "  Login" << endl;
		for (int i = 0; i < 20; i++)
			cout << "_";
		cout << endl;
		//List of accs
		for (int i = 0; i < accs.size(); i++)
			cout << i+1 << ") |" <<  accs[i].getLogin() << endl;

		cout << endl << " \t1) Add account" << endl;
		cout << " \t2) Delete account" << endl;
		cout << " \t0) exit" << endl;
		cout << "Your choice: ";
		flag = inputInt(0, 2);

		switch (flag)
		{
		case 1:
		{
			cout << endl << "~Add account~ " << endl;
			Account currAcc;
			bool f = false;
			do{
			currAcc.inputAcc();
			if (currAcc.validLogin(accs)) {
				accs.push_back(currAcc);
				objAddInTxtFile(currAcc, ACCOUNT);
				

			}
			else {
				cout << "This login is already taken" << endl;
				cout << "To try again enter [1], other [0]: ";
				cin >> f;
				cout << endl;
			}
			} while (f);
			//objAddInTxtFile(currAcc, ACCOUNT);

			break;
		}

		case 2:
		{
			cout << endl << "~Choose account to delete (enter 0 to cancel)~ " <<  endl;
			index = inputInt(0, accs.size() + 1);
			if (index == 0)
				break;
			else {
				string delFold =accs[index - 1].getLogin();
				/*char location[100];
				_getcwd(location, 100);
				cout << location << endl;*/
				accs.erase(accs.begin() + index - 1);
				vectorAddInBinFile(accs, ACCOUNT);
				delFold = "rmdir /s /q " + delFold;
				system(delFold.c_str());
			}
				

			break;
		}

		

		case 0: {
			return;
		}
		default: break;
		}

	} while (flag != 0);
}


inline void Interface::AccountMenu(Account& acc)
{
	system("CLS");
	//Location
	char location[100];
	_getcwd(location, 100);
	_mkdir(acc.getLogin().c_str());
	_chdir(acc.getLogin().c_str());

	//Установка валюты по умолчанию, елси ее не было в файле
	fromTextFileInVector(acc._curr, CURR);
	acc.setDefaultCurrType("BYN");
	if (true) {
		Currency a("",0,0);
		if (acc.getCurrDefault() == a) {
			a.setCCurr(1.00);
			a.setVCurr(1.00);
			a.setTCurr("BYN");
			acc._curr.push_back(a);
			acc.setDefaultCurrType("BYN");
		}
	}

	
	//Установка счета по умолчанию, елси ее не было в файле
	fromTextFileInVector(acc._bankAcc, BANKACCOUNT);
	if (acc._bankAcc.empty()) {
		cout << "Please, add bank account" << endl;
		BankAccount temp;
		acc.addBankAccount();
		temp = acc._bankAcc[0];
		acc._bankAcc.push_back(temp);
		acc.setBankAccDefault(temp);
		vectorAddInTxtFile(acc._bankAcc, BANKACCOUNT);
	}
	else {
		acc.setBankAccDefault(acc._bankAcc[0]);
	}
		
	//Доходы
	MyRing<OtherIncome> accOI;
	fromTxtFileInRing(accOI, OTHERINCOME);
	if(toCompleteTransactions(accOI,acc))	//Выполнение периодических транзакций
		ringAddInTxtFile(accOI, OTHERINCOME);

	//Рассходы
	MyRing<Expenses> accExp;
	fromTxtFileInRing(accExp,  EXPENSES);
	if(toCompleteTransactions(accExp,acc))	//Выполнение периодических транзакций
		ringAddInTxtFile(accExp, EXPENSES);

	//Вклады
	MyRing<Deposit> accDep;	
	fromTxtFileInRing(accDep, DEPOSIT);
	if(toCompleteTransactions(accDep, acc))	//Выполнение периодических транзакций
		ringAddInTxtFile(accDep, DEPOSIT);

	int flag = 0;
	do {
		system("CLS");
		cout << "\t\t~Account Menu~" << endl << endl;
		cout << " \t1) Income" << endl; 
		cout << " \t2) Expenses" << endl;
		cout << " \t3) Deposit" << endl; 
		cout << " \t4) Bank accounts" << endl; 
		cout << " \t5) Currency" << endl;
		cout << " \t6) View Income" << endl; 
		cout << " \t6) View Expenses" << endl; 
		cout << " \t7) View Deposit" << endl; 
		cout << " \t0) exit" << endl;
		cout << endl << "Your choice: ";
		flag = inputInt(0, 8);

		switch (flag)
		{

		case 1:
		{
			Interface::TransMenu(accOI, acc, 1);
			break;
		}

		case 2:
		{
			Interface::TransMenu(accExp, acc, 2);
			break;
		}

		case 3:
		{
			Interface::TransMenu(accDep, acc, 3);
			break;
		}

		case 4:
		{
			Interface::BankAccMenu(acc);
			break;
		}
		case 5:
		{
			Interface::CurrencyMenu(acc);

			break;
		}
		case 6:
		{
			viewMenu(accOI, 1);
			break;
		}
		case 7:
		{
			viewMenu(accExp, 2);
			break;		
		}
		case 8:
		{
			viewMenu(accDep, 1);
			break;
		}


		case 0: {
			flag = 0;
			break;
		}
		default: break;
		}

	} while (flag != 0);
	
	_chdir(location);
}


template<typename T> 
inline void Interface::viewMenu(MyRing<T>& trans, int type) {
	int flag = 0, index = 0;
	MyRing<T> currRing;
	do {
		system("CLS");
		if (type == 1)
			cout << "\t\t~Income~ " << endl << endl;
		else if (type == 2)
			cout << "\t\t~Expenses~ " << endl << endl;
		else if (type == 3)
			cout << "\t\t~Deposit~ " << endl << endl;
	
		if (currRing.getSize() == -1) {
			cout << "Select action" << endl;
		}
		else {
			currRing.getTail()->data.displayShow();
			currRing.printTransaction();
		}

		cout << endl << endl << " \t1) Print all transactions" << endl;
		cout << " \t2) View from (dd.mm.yyyy) to (dd.mm.yyyy)" << endl;
		cout << " \t3) Descending sort by date" << endl;
		cout << " \t4) Ascending sort by date" << endl;
		cout << " \t0) exit" << endl;

		cout << endl << "Your choice: ";
		flag = inputInt(0, 7);
		switch (flag)
		{
		case 1:
		{
			currRing = trans;
			break;
		}

		case 2:
		{
			currRing = transactionsFromTo(currRing);
			//system("pause");
			break;
		}
		case 3:
		{
			Iterator<T> begin = currRing.Begin();
			sortDescendingRing(begin, currRing.getSize());
			break;
		}
		case 4:
		{
			Iterator<T> begin = currRing.Begin();
			sortAscendingRing(begin, currRing.getSize());
			break;
		}

		case 0: {
			return;
		}
		default: break;
		}



	} while (flag != 0);
}

inline void Interface::coutDeposit()
{
	cout << "\t\t~Deposit~ " << endl << endl;
	cout << " \t1) Add One-time deposit" << endl;
	cout << " \t2) Periodic deposit" << endl;
	cout << " \t3) Delete periodic deposit" << endl;

}

inline void Interface::coutIncome()
{
	cout << "\t\t~Income~ " << endl << endl;
	cout << " \t1) Add One-time income" << endl;
	cout << " \t2) Periodic income" << endl;
	cout << " \t3) Delete periodic income" << endl;

}

inline void Interface::coutExpenses()
{
	cout << "\t\t~Expenses~ " << endl << endl;
	cout << " \t1) Add One-time expenses" << endl;
	cout << " \t2) Periodic expenses" << endl;
	cout << " \t3) Delete periodic expenses" << endl;

}


template <typename T>
inline void Interface::TransMenu(MyRing<T>& trans, Account& acc, int type) {
	MyRing<T> perRing;
	int flag = 0, index = 0;
	vector<MyRing<T>> cancelTrans;
	vector<vector<BankAccount>> cancelBankAcc;
	vector<BankAccount> cancelBankDef;
	do {
		system("CLS");
		cout << "\t\t~Your transactions~ " << endl << endl;		
		
			cout << "\t\tYour periodical transactions" << endl;
			trans.getTail()->data.displayShow();
			perRing = printObligatory(trans);
			perRing.printTransaction();
		
		if (type != 3) {
			cout << endl << "\t\tYour 5 last one-time transactions" << endl;
			trans.getTail()->data.displayShow();
			printNotObligatoryCount(trans, 5);
			cout << endl;
		}		
		if (type == 1)
			coutIncome();
		else if (type == 2)
			coutExpenses();
		else if (type == 3)
			coutDeposit();
		// 1) Add One-time 
		// 2) Periodic 
		// 3) Delete periodic
		cout << " \t4) Currency setting" << endl;
		cout << " \t5) My bank accounts" << endl;
		cout << " \t6) Cancel action" << endl;		
		cout << " \t0) exit" << endl;
		cout << endl << "On your bank account [" << acc.getBankAccDefault().getName() << "] remaning money in default currency: " << acc.getBankAccDefault().getMoney() * acc.getCurrDefault().getCCurr() << " " << acc.getCurrDefault().getTCurr();
		cout << endl << "Your choice: ";
		flag = inputInt(0, 6);
		
		switch (flag)
		{

		case 1:
		{
			//Вклад не имеет разового добавления 
			if (type != 3) {
				cancelTrans.push_back(trans);
				cancelBankDef.push_back(acc.getBankAccDefault());
				cancelBankAcc.push_back(acc._bankAcc);
				trans.inputTransaction(0);
				trans.Begin()->data.converting(acc.getCurrDefault().getCCurr());

				if (!trans.Begin()->data.procBankAcc(acc)) {
					trans.deleteTransaction(0);
					cout << "There are not enough money in your account" << endl;
					system("pause");
					break;
				}
					if (type == 1) {
					vectorAddInTxtFile(acc._bankAcc, BANKACCOUNT);
					objAddInTxtFile(trans.Begin()->data, OTHERINCOME);
					}
					else if (type == 2) {
						vectorAddInTxtFile(acc._bankAcc, BANKACCOUNT);
						objAddInTxtFile(trans.Begin()->data, EXPENSES);
					}

			} 
			else {
				cout << "You can't add one-time deposit" << endl;
				system("pause");
			}
			break;
		}

		case 2:
		{
			cancelBankDef.push_back(acc.getBankAccDefault());
			cancelTrans.push_back(trans);
			cancelBankAcc.push_back(acc._bankAcc);
			trans.inputTransaction(0);			
			trans.Begin()->data.converting(acc.getCurrDefault().getCCurr());
			cout << "Period (dd.mm.yyyy): ";
			trans.Begin()->data.setPeriodC();
			
			if (!trans.Begin()->data.procBankAcc(acc)) {
				trans.deleteTransaction(0);
				cout << "There are not enough money in your account" << endl;
				system("pause");
				break;
			}

			if (type == 1) {
				vectorAddInTxtFile(acc._bankAcc, BANKACCOUNT);
				objAddInTxtFile(trans.Begin()->data, OTHERINCOME);
			}
			else if (type == 2) {
					vectorAddInTxtFile(acc._bankAcc, BANKACCOUNT);
					objAddInTxtFile(trans.Begin()->data, EXPENSES);
			}
			else if (type == 3) {
					vectorAddInTxtFile(acc._bankAcc, BANKACCOUNT);
					objAddInTxtFile(trans.Begin()->data, DEPOSIT);
			}
			break;
		}

		case 3:
		{
			cancelTrans.push_back(trans);
			cancelBankDef.push_back(acc.getBankAccDefault());
			cancelBankAcc.push_back(acc._bankAcc);
			if (type == 1) cout << endl << endl << "\tYour periodic Incomes" << endl << endl;
			else if (type == 2) cout << endl << endl << "\tYour periodic Expenses" << endl << endl;
			else if (type == 3) cout << endl << endl << "\tYour Deposits" << endl << endl;
			
			trans.getTail()->data.displayShow();
			
			perRing.printTransaction();
			cout << "Input index for delete: " << endl;
			index = inputInt(0, trans.getSize() +1);
			if (index != 0 || trans.getSize() == -1) {
				trans.deleteTransaction(index);
				if (trans.getSize() != -1) {
					if (type == 1) ringAddInTxtFile(trans, OTHERINCOME);
					else if (type == 2) ringAddInTxtFile(trans, EXPENSES);
					else if (type == 3) ringAddInTxtFile(trans, DEPOSIT);
				}
			}
				
			break;
		}

		case 4:
		{
			Interface::CurrencyMenu(acc);
			break;
		}
		
		case 5:
		{
			BankAccMenu(acc);			
			break;
		}
		case 6: 
		{
			if (!cancelTrans.empty() && !cancelBankAcc.empty()) {
				acc.setBankAccDefault(cancelBankDef.at(cancelBankDef.size()-1));
				cancelBankDef.pop_back();
				acc._bankAcc = cancelBankAcc.at(cancelBankAcc.size()-1);
				cancelBankAcc.pop_back();
				trans = cancelTrans.at(cancelTrans.size()-1);
				cancelTrans.pop_back(); 
				
				if (type == 1) {
					vectorAddInTxtFile(acc._bankAcc, BANKACCOUNT);
					ringAddInTxtFile(trans, OTHERINCOME);
				}
				else if (type == 2) {
					vectorAddInTxtFile(acc._bankAcc, BANKACCOUNT);
					ringAddInTxtFile(trans, EXPENSES);
				}
				else if (type == 3) {
					vectorAddInTxtFile(acc._bankAcc, BANKACCOUNT);
					ringAddInTxtFile(trans, DEPOSIT);
				}
			}
			
			break;
		}

		

		case 0: {
			return;
		}
		default: break;
		}
	} while (flag != 0);
}

inline void Interface::BankAccMenu(Account& acc) {
	int flag = 0, index = 0;
	vector<BankAccount> defBA;
	vector<vector<BankAccount>> vecBA;
	do {
		system("CLS");
		cout << "\t\t~Bank accounts~ " << endl << endl;
		acc._bankAcc.clear();	
		fromTextFileInVector(acc._bankAcc, BANKACCOUNT);
		acc.getBankAccDefault().displayShow();
		acc.printBankAccount();
		cout << endl << endl << " \t1) Add bank account" << endl;
		cout << " \t2) Delete bank account" << endl;
		cout << " \t3) Rename bank account" << endl;
		cout << " \t4) Edit money bank account" << endl;
		cout << " \t5) Set default bank account by index" << endl;
		cout << " \t6) Set default bank account by name" << endl;
		cout << " \t7) Cancel action" << endl;
		cout << " \t0) exit" << endl;

		cout << endl << "Your choice: ";
		flag = inputInt(0, 7);
		switch (flag)
		{
		case 1:
		{
			defBA.push_back(acc.getBankAccDefault());
			vecBA.push_back(acc._bankAcc);
			acc.addBankAccount();
			objAddInTxtFile(acc._bankAcc.back(), BANKACCOUNT);
			break;
		}

		case 2:
		{
			defBA.push_back(acc.getBankAccDefault());
			vecBA.push_back(acc._bankAcc);
			cout << "Input index to delete: ";
			index = inputInt(0, acc._bankAcc.size());
			cout << endl;
			if (index) {
				if (acc.getBankAccDefault() == acc._bankAcc[index]) {
					cout << "You can't to delete default bank account " << endl;
					system("pause");
					break;
				}
				else {
					acc._bankAcc.erase(acc._bankAcc.begin() + index - 1);
					vectorAddInTxtFile(acc._bankAcc, BANKACCOUNT);
				}

			}
			break;
		}

		case 3:
		{
			defBA.push_back(acc.getBankAccDefault());
			vecBA.push_back(acc._bankAcc);
			cout << "Input index to rename: ";
			index = inputInt(0, acc._bankAcc.size());
			string str;
			if (index != 0) {
				cout << endl << "Enter name of bank account: ";
				cin >> str;
				if (acc._bankAcc.at(index).getName() == acc.getBankAccDefault().getName()) {
					acc._bankAcc.at(index).setName(str);
					acc.getBankAccDefault().setName(str);
				}
				else
					acc._bankAcc.at(index).setName(str);
				vectorAddInTxtFile(acc._bankAcc, BANKACCOUNT);
			}
				
			break;
		}
		case 4:
		{
			defBA.push_back(acc.getBankAccDefault());
			vecBA.push_back(acc._bankAcc);
			cout << "Input index to edit money: " ;
			index = inputInt(0, acc._bankAcc.size());
			string str;
			
			cout << endl;
			if (index != 0) {
				cout << "Enter new money: ";
				float amount;
				cin >> amount;
				if (acc.getBankAccDefault() == acc._bankAcc.at(index)) {
					acc._bankAcc.at(index).setMoney(amount);
					acc.getBankAccDefault().setMoney(amount);
				}
				else
					acc._bankAcc.at(index).setMoney(amount);
				vectorAddInTxtFile(acc._bankAcc, BANKACCOUNT);
			}
			break;
		}
		case 5:
		{
			if (!defBA.empty() && !vecBA.empty()) {
				acc.setBankAccDefault(defBA.at(defBA.size() - 1));
				defBA.pop_back();
				acc._bankAcc = vecBA.at(vecBA.size() - 1);
				vecBA.pop_back();
				//vectorAddInTxtFile(acc._curr, CURR);
				vectorAddInTxtFile(acc._bankAcc, BANKACCOUNT);
			}
			break;
		}

		case 0: {
			return;
		}
		default: break;
		}



	} while (flag != 0);
}

inline void Interface::CurrencyMenu(Account& acc)
{
	int flag = 0, index = 0;
	vector<Currency> defCurr;
	vector<vector<Currency>> vecCurr;
	string str;
	do {
		system("CLS");
		cout << "\t\t~Currency menu~ " << endl << endl;
		if (acc._curr.size() == 0)
			cout << "\t~Default currency is empty~ " << endl << endl;
		else cout << "\tDefault currency: " << acc.getCurrDefault().getTCurr() << endl << endl;

		//Вывод на экран 
		acc._curr.at(0).displayShow();
		for (int i = 0; i < acc._curr.size(); i++) {
			cout << acc._curr[i] << endl;
		}
		cout << endl << endl << " \t1) Add currency (type and value)" << endl;
		cout << " \t2) Add currency (type and coefficient)" << endl;
		cout << " \t3) Set default by index" << endl;
		cout << " \t4) Set default by name" << endl;
		cout << " \t5) Delete currency" << endl;
		cout << " \t6) Delete all currancy" << endl;
		cout << " \t7) Cancle action" << endl;
		cout << " \t0) exit" << endl;

		cout << endl << "Your choice: ";
		flag = inputInt(0, 7);
		switch (flag)
		{
		case 1:
		{
			defCurr.push_back(acc.getCurrDefault());
			vecCurr.push_back(acc._curr);
			if (acc._curr.size() == 0) {
				cout << "Error, please, try to add FIRST DEFAULT currency" << endl;
				system("CLS");
			}
			else acc.addValueCurr();
			vectorAddInTxtFile(acc._curr, CURR);
			break;
		}

		case 2:
		{
			defCurr.push_back(acc.getCurrDefault());
			vecCurr.push_back(acc._curr);
			if (acc._curr.size()  == 0) {
				cout << "Error, please, try to add FIRST DEFAULT currency" << endl;
				system("CLS");
			} 
			else acc.addCoefCurr();
			vectorAddInTxtFile(acc._curr, CURR);
			break;
		}
		case 3:
		{
			defCurr.push_back(acc.getCurrDefault());
			vecCurr.push_back(acc._curr);
			cout << "Input index of currency  to set default: ";
			index = inputInt(0, acc._curr.size());
			cout << endl;
			if (index) {
				acc.setDefaultCurr(index-1);
			}			
			break;
		}
		case 4:
		{
			cout << "Input name of currency to set default: ";
			str = inputString(4);
			cout << endl;
			acc.setDefaultCurrType(str);
			break;
		}
		case 5:
		{
			defCurr.push_back(acc.getCurrDefault());
			vecCurr.push_back(acc._curr);
			cout << "Input index of currency to delete: ";
			index = inputInt(0, acc._curr.size()+1);
			cout << endl;
			if (index) {
				if (acc.getCurrDefault() == acc._curr[index - 1]) {
					cout << "This currency is default" << endl;
					system("pause");
					break;
				}
				else {
					acc._curr.erase(acc._curr.begin() + index - 1);
					vectorAddInTxtFile(acc._curr, CURR);
				}					
			}
			
			break;
		}
		case 6:
		{
			defCurr.push_back(acc.getCurrDefault());
			vecCurr.push_back(acc._curr);
			cout << endl << "Enter 1 - to continue, 0 - to exit: ";
			flag = inputInt(0, 1);
			if (flag == 1) {
				acc._curr.clear();
				acc._curr.push_back(acc.getCurrDefault());
				vectorAddInTxtFile(acc._curr, CURR);
			}
			break;
		}
		case 7:
		{
			if (!defCurr.empty() && !vecCurr.empty()) {
				acc.setCurrDefault(defCurr.at(defCurr.size() - 1));
				defCurr.pop_back();
				acc._curr = vecCurr.at(vecCurr.size() - 1);
				vecCurr.pop_back();

				vectorAddInTxtFile(acc._curr, CURR);
			}
			break;
		}
		case 0: {
			if (acc._curr.empty()) {
				Currency temp;
				temp.setCCurr(1.00);
				temp.setVCurr(1.00);
				temp.setTCurr("BYN");
				acc._curr.push_back(temp);
				acc.setDefaultCurrType("BYN");
			}
			return;
		}
		default: break;
		}
	} while (flag != 0);
}

