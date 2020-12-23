#pragma once
#include "Header.h"
class Income: public Transaction
{
protected:
	string _source;

public:
	Income() :Transaction(), _source("") {};
	Income(Date period, Date date, float money, float dirtyMoney, string source) :Transaction(period, date, money, dirtyMoney), _source(source) {};
	~Income(){};
	
	string getSource() { return _source; }
	void setSource(string& source) { _source = source; };

	friend istream& operator>>(istream& in, Income& obj);
	friend ostream& operator<<(ostream& out, Income& obj);
	friend fstream& operator>>(fstream& in, Income& obj);
	friend fstream& operator<<(fstream& out, Income& obj);
	friend ifstream& operator>>(ifstream& in, Income& obj);
	friend ofstream& operator<<(ofstream& out, Income& obj);
};