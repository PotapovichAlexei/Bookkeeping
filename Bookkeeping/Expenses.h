#pragma once
#include "Header.h"
class Expenses : public Transaction
{
protected:
	string _objOfCons;	//obj of consumption
	
	
public:
	Expenses() :Transaction(), _objOfCons("") {};
	Expenses(Date period, Date date, float money, float dirtyMoney, string objOfCons) :
		Transaction(period, date, money, dirtyMoney), _objOfCons(objOfCons) {};
	//Expenses(string objOfCons) :Transaction(), _objOfCons(objOfCons) {};
	~Expenses() {};

	bool operator< (const Expenses& obj);
	bool operator> (const Expenses& obj);
	bool operator<= (const Expenses& obj);
	bool operator>= (const Expenses& obj);
	bool operator== (const Expenses& obj);
	string getObjOfCons() { return _objOfCons; }
	void setObjOfCons(string& objOfCons) { _objOfCons = objOfCons; };
	void calculate() {};
	void converting(float defaultCurrency) { _money = _money / defaultCurrency; }
	friend istream& operator>>(istream& in, Expenses& obj);
	friend ostream& operator<<(ostream& out, Expenses& obj);
	friend fstream& operator>>(fstream& in, Expenses& obj);
	friend fstream& operator<<(fstream& out, Expenses& obj);
	friend ifstream& operator>>(ifstream& in, Expenses& obj);
	friend ofstream& operator<<(ofstream& out, Expenses& obj);
	bool procBankAcc(Account& obj);
	bool equal(Expenses& obj);
	void displayShow();
};