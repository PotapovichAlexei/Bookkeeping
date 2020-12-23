#pragma once
#include "Header.h"
class BankAccount {
private:
	string _nameBankAccount;
	float _amountMoney;
public:
	BankAccount() :
		_nameBankAccount(""), _amountMoney(0.0) {};
	BankAccount(string nameBankAccounting, float amountMoney) :
		_nameBankAccount(nameBankAccounting), _amountMoney(amountMoney) {};
	~BankAccount() {};

	BankAccount(const BankAccount& obj);

	string getName() { return this->_nameBankAccount; }
	void setName(string name) { this->_nameBankAccount= name; }
	float getMoney() { return this->_amountMoney; }
	void setMoney(float money) {  this->_amountMoney=money; }

	friend istream& operator>>(istream& in, BankAccount& obj);
	friend ostream& operator<<(ostream& out, BankAccount& obj);

	friend fstream& operator>>(fstream& in, BankAccount& obj);
	friend fstream& operator<<(fstream& out, BankAccount& obj);
	friend ifstream& operator>>(ifstream& in, BankAccount& obj);
	friend ofstream& operator<<(ofstream& out, BankAccount& obj);

	bool operator==(BankAccount&);

	void displayShow();
};