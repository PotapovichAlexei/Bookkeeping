#pragma once
#include "Header.h"

class Transaction {
protected:
	Date _date;
	//vector<Currency> _curr;
	//Currency _currDefault;
	float _money;
	float _dirtyMoney;
	Date _period;
public: 
	//Constructors and Distructor
	Transaction() : _period(),_date(), _money(0.0), _dirtyMoney(0.0) {};
	Transaction(Date period, Date date, float money, float dirtyMoney) : _period(period), _date(date), _money(money), _dirtyMoney(dirtyMoney) {};
	~Transaction() {};

	
	//Getters and Setters
	Date getDate() { return _date; }
	void setDate(Date date) { this->_date = date; }
	float getMoney() { return _money; }
	void setMoney(const float& money) { this->_money = money; }
	float getDirtyMoney() { return _dirtyMoney; }
	void setDirtyMoney(const float& money) { this->_money = _dirtyMoney; }
	Date getPeriod() { return _period; }
	void setPeriod(Date period) { this->_period = period; }
	
	void setPeriodC();

	friend istream& operator>>(istream& in, Transaction& obj);
	friend ostream& operator<<(ostream& out, Transaction& obj);

	friend fstream& operator>>(fstream& in, Transaction& obj);
	friend fstream& operator<<(fstream& out, Transaction& obj);
	friend ifstream& operator>>(ifstream& in, Transaction& obj);
	friend ofstream& operator<<(ofstream& out, Transaction& obj);
};