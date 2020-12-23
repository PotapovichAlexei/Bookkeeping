#pragma once
#include "Header.h"
class OtherIncome : public Income
{
protected:
	float _perTax; //percentage of contribution
public:
	OtherIncome() : Income(), _perTax(0.0) {};
	OtherIncome(Date period, Date date, float money, float dirtyMoney, string source, float perTax) :
		Income(period, date, money, dirtyMoney, source), _perTax(perTax) {};
	~OtherIncome() {};


	float getPerTax() { return _perTax; }
	void setPerTax(float& percent) { _perTax = percent; };

	friend istream& operator>>(istream& in, OtherIncome& obj);
	friend ostream& operator<<(ostream& out, OtherIncome& obj);

	friend fstream& operator>>(fstream& in, OtherIncome& obj);
	friend fstream& operator<<(fstream& out, OtherIncome& obj);
	friend ifstream& operator>>(ifstream& in, OtherIncome& obj);
	friend ofstream& operator<<(ofstream& out, OtherIncome& obj);

	void calculate();
	void converting(float defaultCurrency);

	bool operator< (const OtherIncome& obj);
	bool operator> (const OtherIncome& obj);
	bool operator<= (const OtherIncome& obj);
	bool operator>= (const OtherIncome& obj);
	bool operator== (const OtherIncome& obj);
	bool procBankAcc(Account& obj);
	bool equal(OtherIncome& obj);
	void displayShow();
};