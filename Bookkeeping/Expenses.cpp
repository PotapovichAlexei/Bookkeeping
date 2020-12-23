//#include "Expenses.h"
//#include "Exception.h"
#include "Header.h"
istream& operator>>(istream& in, Expenses& obj)
{
	in >> dynamic_cast<Transaction&> (obj);
	rewind(stdin);
	cout << "Object of consumption: ";

	obj._objOfCons = inputString(15);
	obj.calculate();
	return in;
}

ostream& operator<<(ostream& out, Expenses& obj) {
	out << dynamic_cast<Transaction&> (obj) << setw(21) << obj._objOfCons << "|";
	Date a(0, 0, 0);
	if (obj._period == a)
		out << setw(12) << "one-time|";
	else
		out << obj._period << "|";
	return out;
}


fstream& operator>>(fstream& in, Expenses& obj)
{
	in >> dynamic_cast<Transaction&> (obj);
	in >> obj._objOfCons;
	return in;
}

fstream& operator<<(fstream& out, Expenses& obj) {
	out << dynamic_cast<Transaction&> (obj);
	out << obj._objOfCons << "\n";
	return out;
}

ifstream& operator>>(ifstream& in, Expenses& obj)
{
	in >> dynamic_cast<Transaction&> (obj);
	in >> obj._objOfCons;
	return in;
}

ofstream& operator<<(ofstream& out, Expenses& obj) {
	out << dynamic_cast<Transaction&> (obj);
	out << obj._objOfCons << "\n";
	return out;
}


bool Expenses::operator<(const Expenses& obj)
{
	if (this->_date < obj._date)
		return true;
	return false;
}

bool Expenses::operator>(const Expenses& obj)
{
	if (this->_date > obj._date)
		return true;
	return false;
}

bool Expenses::operator<=(const Expenses& obj)
{
	if (this->_date <= obj._date)
		return true;
	return false;
}

bool Expenses::operator>=(const Expenses& obj)
{
	if (this->_date >= obj._date)
		return true;
	return false;
}

bool Expenses::operator== (const Expenses& obj)
{
	if (this->_date == obj._date)
		return true;
	return false;
}

bool Expenses::procBankAcc(Account& obj)
{
	BankAccount def = obj.getBankAccDefault();

	for (int i = 0; i < obj._bankAcc.size(); i++) {
		if (obj._bankAcc[i] == def) {
			if (obj._bankAcc[i].getMoney() - this->_money > -0.001) {
				obj._bankAcc[i].setMoney(obj._bankAcc[i].getMoney() - this->_money);
				obj.setBankAccDefault(obj._bankAcc[i]);
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

bool Expenses::equal(Expenses& obj)
{
	if (this->getDate() == obj.getDate() && this->getDirtyMoney() == obj.getDirtyMoney() && this->getMoney() == obj.getMoney() && this->getObjOfCons() == obj.getObjOfCons() &&
		this->getPeriod() == obj.getPeriod())
		return true;
	return false;
}

void Expenses::displayShow()
{
	cout << "|"; for (int i = 0; i < 56; i++) cout << "~"; cout << "|" << endl;
	cout << "|" << setw(10) << "Date" << "|" <<  setw(11) << "Money" << "|" << setw(21) << "Object of consumption|" << setw(12) << "Period|" << endl;
	cout << "|"; for (int i = 0; i < 56; i++) cout << "~"; cout << "|" << endl;
}
