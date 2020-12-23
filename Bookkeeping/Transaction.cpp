//#include "Transaction.h"
#include "Header.h"
//#include "Exception.h"

istream& operator>>(istream& in, Transaction& obj)
{
	//rewind(stdin);
	//cout << "Obligatory: ";
	//obj._obligatory = inputInt(0,1);
	
	rewind(stdin);
	in >> obj._date;
	
	rewind(stdin);
	cout << "Money: ";
	obj._dirtyMoney = inputFloatWS();
	obj._money = obj._dirtyMoney;
	return in;
}

ostream& operator<<(ostream& out, Transaction& obj) {
	out << "|" << obj._date << "|" << setw(11) << obj._money <<  "|";
	return out;
}



fstream& operator>>(fstream& in, Transaction& obj)
{
	in >> obj._date;
	in >> obj._money;
	in >> obj._dirtyMoney;
	in >> obj._period;

	return in;
}

fstream& operator<<(fstream& out, Transaction& obj) {
	out << obj._date << " ";
	out << obj._money << " ";
	out << obj._dirtyMoney << " ";
	out << obj._period << " ";
	return out;
}

ifstream& operator>>(ifstream& in, Transaction& obj)
{
	in >> obj._date;
	in >> obj._money;
	in >> obj._dirtyMoney;
	in >> obj._period;

	return in;
}

ofstream& operator<<(ofstream& out, Transaction& obj) {
	out << obj._date << " ";
	out << obj._money << " ";
	out << obj._dirtyMoney << " ";
	out << obj._period << " ";
	return out;
}

void Transaction::setPeriodC()
{
	int* a = new int[3];
	a = inputDate();
	this->_period.setDay(a[0]);
	this->_period.setMonth(a[1]);
	this->_period.setYear(a[2]);
}
