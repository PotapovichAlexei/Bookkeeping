#pragma once
#include "Header.h"
#include "BankAccount.h"
#include "Currency.h"

class Account
{
private:
	string _login;
	string _password;

	BankAccount _bankAccDefault;
	Currency _currDefault;
public:	
	vector<Currency> _curr;
	vector<BankAccount> _bankAcc;
	
public:
	Account() : _login(""), _password("") {};
	Account(vector<BankAccount> bankAcc);
	Account(const Account& obj);
	~Account() {};
	void inputAcc();
	void printAcc();

	void addBankAccount();
	void printBankAccount();
	bool subtractionBankAccount(float size);
	void additonalBankAccount(float size);

	string getLogin() { return this->_login; }
	void setLogin(string login) { this->_login = login; }
	string getPassword() { return this->_password; }
	void setPassword(string password) { this->_password = password; }

	bool const operator==(Account& obj);
	bool const checkValidAcc(vector<Account> arr);
	bool const validLogin(vector<Account> arr);

	Currency getCurrDefault() { return _currDefault; }
	void setCurrDefault(Currency curr) { _currDefault = curr; }

	BankAccount getBankAccDefault() { return _bankAccDefault; }
	void setBankAccDefault(BankAccount curr) { _bankAccDefault = curr; }

	vector<Currency> getCurr() { return this->_curr; }
	void setCurr(vector<Currency> curr) { this->_curr = curr; }

	void addCurr();			//Добавить валюту по умолчанию
	void addCoefCurr();		//Добавить валюту по коеффициенту
	void addDefCurr();		//Добавить валюту по умолчанию
	void addValueCurr();	//Добавить валюту по значению

	void setDefaultCurr(int index);			//Устновить валюту по умолчанию по индексу
	void setDefaultCurrType(string type);	//Установить валюту по умолчанию по типу

	void setDefaultBankAcc(int index);			//Установить счет по индексу
	void setDefaultBankAccByName(string type);	//Установить счет по умолчнию по имени

	friend fstream& operator>>(fstream& in, Account& obj);
	friend fstream& operator<<(fstream& out, Account& obj);
	friend ifstream& operator>>(ifstream& in, Account& obj);
	friend ofstream& operator<<(ofstream& out, Account& obj);
};