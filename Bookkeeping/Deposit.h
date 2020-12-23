#pragma once
#include "Header.h"
class Deposit: public Income
{
private:
	float _perDeposit; //percentage of contribution
public:
	Deposit() : Income(), _perDeposit(0.0) {};
	Deposit(Date period, Date date, float money, float dirtyMoney, string source, float percent) :
		Income(period, date, money, dirtyMoney, source), _perDeposit(percent) {};
	~Deposit() {};

	float getPercent() { return _perDeposit; }
	void setPercent (float& percent) { _perDeposit = percent; };

	friend istream& operator>>(istream& in, Deposit& obj);
	friend ostream& operator<<(ostream& out, Deposit& obj);

	friend fstream& operator>>(fstream& in, Deposit& obj);
	friend fstream& operator<<(fstream& out, Deposit& obj);
	friend ifstream& operator>>(ifstream& in, Deposit& obj);
	friend ofstream& operator<<(ofstream& out, Deposit& obj);

	void calculate();
	void converting(float defaultCurrency);

	bool operator< (const Deposit& obj);
	bool operator> (const Deposit& obj);
	bool operator<= (const Deposit& obj);
	bool operator>= (const Deposit& obj);
	bool operator== (const Deposit& obj);

	bool procBankAcc(Account& obj);
	bool equal(Deposit& obj);
	void displayShow();
};

