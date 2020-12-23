//#include "Deposit.h"
#include "Header.h"
//#include "Exception.h"

istream& operator>>(istream& in, Deposit& obj)
{
	in >> dynamic_cast<Income&> (obj);
	rewind(stdin);
	cout << "Percentage of deposit: ";
	obj._perDeposit = inputFloatWS();
	obj.calculate();
	return in;
}

ostream& operator<<(ostream& out, Deposit& obj) {
	out << dynamic_cast<Income&> (obj) << setw(20) << obj._perDeposit << "%|";
	Date a(0, 0, 0);
	if (obj._period == a)
		out << setw(11) << "one-time|";
	else
		out << obj._period << "|";
	
	return out;
}

fstream& operator>>(fstream& in, Deposit& obj)
{
	in >> dynamic_cast<Income&> (obj); 
	in >> obj._perDeposit;
	return in;
}

fstream& operator<<(fstream& out, Deposit& obj) {
	out << dynamic_cast<Income&> (obj);
	out << obj._perDeposit << "\n";
	return out;
}

ifstream& operator>>(ifstream& in, Deposit& obj)
{
	in >> dynamic_cast<Income&> (obj);
	in >> obj._perDeposit;
	return in;
}

ofstream& operator<<(ofstream& out, Deposit& obj) {
	out << dynamic_cast<Income&> (obj);
	out << obj._perDeposit << "\n";
	return out;
}

void Deposit::calculate()
{
	_money = _dirtyMoney * (1 + (_perDeposit / 100)) - _dirtyMoney;
}

void Deposit::converting(float defaultCurrency)
{
	_dirtyMoney = _dirtyMoney/ defaultCurrency;
	_money = _money/defaultCurrency;
}


bool Deposit::operator<(const Deposit& obj)
{
	if (this->_date < obj._date)
		return true;
	return false;
}

bool Deposit::operator>(const Deposit& obj)
{
	if (this->_date > obj._date)
		return true;
	return false;
}

bool Deposit::operator<=(const Deposit& obj)
{
	if (this->_date <= obj._date)
		return true;
	return false;
}

bool Deposit::operator>=(const Deposit& obj)
{
	if (this->_date >= obj._date)
		return true;
	return false;
}

bool Deposit::operator== (const Deposit& obj)
{
	if (this->_date == obj._date)
		return true;
	return false;
}


bool Deposit::procBankAcc(Account& obj)
{
	BankAccount def = obj.getBankAccDefault();

	for (int i = 0; i < obj._bankAcc.size(); i++) {
		if (obj._bankAcc[i] == def) {
			obj._bankAcc[i].setMoney(obj._bankAcc[i].getMoney() + this->_money);
			obj.setBankAccDefault(obj._bankAcc[i]);
			return true;
		}
	}
	return false;
}

bool Deposit::equal(Deposit& obj)
{
	if (this->getDate() == obj.getDate() && this->getDirtyMoney() == obj.getDirtyMoney() && this->getMoney() == obj.getMoney() && this->getPercent() == obj.getPercent() &&
		this->getPeriod() == obj.getPeriod() && this->getSource() == obj.getSource())
		return true;
	return false;
}

void Deposit::displayShow()
{
	cout << "|";  for (int i = 0; i < 79; i++) cout << "~"; cout << "|" << endl;
	cout << "|" << setw(10) << "Date " << "|" << setw(11) << "Money" << "|" << setw(1) << "Dirty money" << "|" << setw(11) << "Number Acc" << "|" << setw(18) << "Percentage of deposit|" << setw(11) << "Period|" << endl;
	cout << "|"; for (int i = 0; i < 79; i++) cout << "~"; cout << "|" << endl;
}
