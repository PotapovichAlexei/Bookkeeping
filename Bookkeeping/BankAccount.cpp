//#include"BankAccount.h"
//#include"Exception.h"
#include"Header.h"


std::istream& operator>>(std::istream& in, BankAccount& obj)
{
	rewind(stdin);
	cout << "Name of bank Account: ";
	obj._nameBankAccount = inputString(17);

	rewind(stdin);
	cout << "Money: ";
	obj._amountMoney = inputFloatWS();
	return in;
}

ostream& operator<<(ostream& out, BankAccount& obj) {
	out << "|" << setw(17) << obj._nameBankAccount <<"|"<< setw(17) << obj._amountMoney<< "|";
	return out;
}

fstream& operator>>(fstream& in, BankAccount& obj)
{
	in >> obj._nameBankAccount;
	in >> obj._amountMoney;
	return in;
}

fstream& operator<<(fstream& out, BankAccount& obj) {
	out << obj._nameBankAccount << " ";
	out << obj._amountMoney << "\n";
	return out;
}

ifstream& operator>>(ifstream& in, BankAccount& obj)
{
	in >> obj._nameBankAccount;
	in>> obj._amountMoney;
	return in;
}

ofstream& operator<<(ofstream& out, BankAccount& obj) {
	out << obj._nameBankAccount << " ";
	out << obj._amountMoney << "\n";
	return out;
}


BankAccount::BankAccount(const BankAccount& obj)
{
	this->_amountMoney = obj._amountMoney;
	this->_nameBankAccount = obj._nameBankAccount;
}


void BankAccount::displayShow()
{
	cout << "|"; for (int i = 0; i < 35; i++) cout << "~"; cout << "|" << endl;
	cout << "|" << setw(17) << "Name " << "|" << setw(17) << "Money " << "|" << endl;
	cout << "|"; for (int i = 0; i < 35; i++) cout << "~"; cout << "|" << endl;
}

bool BankAccount::operator==(BankAccount& obj)
{
	if (this->_amountMoney == obj.getMoney() && this->_nameBankAccount == obj.getName())
		return true;
	return false;
}
