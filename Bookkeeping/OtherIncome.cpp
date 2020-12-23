//#include "OtherIncome.h"
#include "Header.h"
//#include "Exception.h"

istream& operator>>(istream& in, OtherIncome& obj)
{
	in >> dynamic_cast<Income&> (obj);

	rewind(stdin);
	cout << "Percentage of tax: ";
	obj._perTax = inputFloatWS();
	obj.calculate();
	return in;
}

ostream& operator<<(ostream& out, OtherIncome& obj) {
	out << dynamic_cast<Income&> (obj) << setw(5) << obj._perTax << "%|";
	Date a(0, 0, 0);
	if (obj._period == a)
		out << setw(11) << "one-time|";
	else
		out << obj._period << "|";
	
	return out;

}

fstream& operator>>(fstream& in, OtherIncome& obj)
{
	in >> dynamic_cast<Income&> (obj);
	in >> obj._perTax;
	return in;
}

fstream& operator<<(fstream& out, OtherIncome& obj) {
	out << dynamic_cast<Income&> (obj);
	out << obj._perTax << "\n";
	return out;
}

ifstream& operator>>(ifstream& in, OtherIncome& obj)
{
	in >> dynamic_cast<Income&> (obj);
	in >> obj._perTax;
	return in;
}

ofstream& operator<<(ofstream& out, OtherIncome& obj) {
	out << dynamic_cast<Income&> (obj);
	out << obj._perTax << "\n";
	return out;
}

void OtherIncome::calculate()
{
	_money = _dirtyMoney * (1 - (_perTax / 100));
}

void OtherIncome::converting(float defaultCurrency)
{
	_dirtyMoney = _dirtyMoney / defaultCurrency;
	_money = _money / defaultCurrency;
}


bool OtherIncome::operator<(const OtherIncome& obj)
{
	if (this->_date < obj._date)
		return true;
	return false;
}

bool OtherIncome::operator>(const OtherIncome& obj)
{
	if (this->_date > obj._date)
		return true;
	return false;
}

bool OtherIncome::operator<=(const OtherIncome& obj)
{
	if (this->_date <= obj._date)
		return true;
	return false;
}

bool OtherIncome::operator>=(const OtherIncome& obj)
{
	if (this->_date >= obj._date)
		return true;
	return false;
}

bool OtherIncome::operator== (const OtherIncome& obj)
{
	if (this->_date == obj._date)
		return true;
	return false;
}

bool OtherIncome::procBankAcc(Account& obj)
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

bool OtherIncome::equal(OtherIncome& obj)
{
	if (this->getDate() == obj.getDate() && this->getDirtyMoney() == obj.getDirtyMoney() && this->getMoney() == obj.getMoney() && this->getPerTax() == obj.getPerTax() &&
		this->getPeriod() == obj.getPeriod() && this->getSource() == obj.getSource())
		return true;
	return false;
}

void OtherIncome::displayShow()
{
	cout << "|";  for (int i = 0; i < 64; i++) cout << "~"; cout << "|" << endl;
	cout << "|" << setw(10) << "Date" << "|" << setw(11) << "Money" << "|" << setw(11) << "Dirty money" << "|" << setw(11) << "Source" << "|" << setw(7) << "Tax|" << setw(11) << "Period|" << endl;;
	cout << "|";  for (int i = 0; i < 64; i++) cout << "~"; cout << "|" << endl;
}

