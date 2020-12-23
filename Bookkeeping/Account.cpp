#include "Header.h"


Account::Account(vector<BankAccount> bankAcc)
{
	this->_bankAcc = bankAcc;
}

Account::Account(const Account& obj)
{
	this->_login = obj._login;
	this->_password= obj._password;
	this->_bankAcc = obj._bankAcc;
}

void Account::inputAcc() {
	rewind(stdin);
	cout << "Login: ";
	this->_login = inputString(17);

	rewind(stdin);
	cout << "Password: ";
	this->_password = stringExceptRussian(17);
}

void Account::printAcc() {
	cout << "Login: " << this->_login << endl;
	cout << "Password: " << this->_password << endl;
}

void Account::addBankAccount()
{
	BankAccount bankAcc;
	cin >> bankAcc;
	_bankAcc.push_back(bankAcc);
}


void Account::printBankAccount()
{
	//cout << "Your bank Accounts: " << endl;
	for (int i = 0; i < this->_bankAcc.size(); i++)
		cout << this->_bankAcc[i] << endl;
}

bool Account::subtractionBankAccount(float size)
{
	BankAccount obj = getBankAccDefault();
	int i;
	for (i = 0; i < _bankAcc.size(); i++) {
		if (_bankAcc[i] == obj) {
			_bankAcc[i].setMoney(this->_bankAcc[i].getMoney() - size);
			getBankAccDefault().setMoney(_bankAcc[i].getMoney());
			break;
		}
	}
	if (getBankAccDefault().getMoney() < 0) {
		_bankAcc[i].setMoney(this->_bankAcc[i].getMoney() - size);
		getBankAccDefault().setMoney(_bankAcc[i].getMoney());
		cout << "There are not enough money in your account" << endl;
		system("pause");
		return false;
	}
	else {
		return true;
	}
	
}

void Account::additonalBankAccount( float size)
{
	BankAccount obj = getBankAccDefault();
	
	for (int i = 0; i < _bankAcc.size(); i++) {
		if (_bankAcc[i] == obj) {
			_bankAcc[i].setMoney(this->_bankAcc[i].getMoney() + size);
			getBankAccDefault().setMoney(_bankAcc[i].getMoney());
			return;
		}
	}
	
}


bool const Account::operator==(Account& obj)
{
	if ((this->getLogin() == obj.getLogin()) && (this->getPassword() == obj.getPassword()))
		return true;
	else
		return false;
}

bool const Account::checkValidAcc(vector<Account> arr)
{
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == *this) return true;
	}
	return false;
}

bool const Account::validLogin(vector<Account> arr)
{
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].getLogin() == this->_login) return false;
	}
	return true;
}


void Account::addCurr()
{
	Currency temp;
	cin >> temp;
	_curr.push_back(temp);
}

void Account::addCoefCurr()
{
	Currency temp;
	cout << "Type: ";
	temp.setTCurr(inputString(4));

	cout << "Coefficient: ";
	temp.setCCurr(inputFloatWS());
	temp.setVCurr(_currDefault.getVCurr() / temp.getCCurr());
	_curr.push_back(temp);
}


void Account::addDefCurr()
{
	Currency temp;
	cout << "Type: ";
	temp.setTCurr(inputString(4));
	temp.setCCurr(1.000);
	temp.setVCurr(1.000);
	_curr.push_back(temp);
}

void Account::addValueCurr()
{
	Currency temp;
	cout << "Type: ";
	temp.setTCurr(inputString(4));

	cout << "Value: ";
	temp.setVCurr(inputFloatWS());
	temp.setCCurr(_currDefault.getVCurr() / temp.getVCurr());
	_curr.push_back(temp);
}


void Account::setDefaultCurr(int index)
{
	_currDefault= _curr.at(index); 
}

void Account::setDefaultCurrType(string type)
{
	int index=0;
	for (int i = 0; i < _curr.size(); i++) {
		if (_curr[i].getTCurr() == type) {
			_currDefault=_curr[i];
			break;
		}
	}
}

void Account::setDefaultBankAccByName(string name)
{
	int index = 0;
	for (int i = 0; i < _bankAcc.size(); i++) {
		if (_bankAcc[i].getName() == name) {
			_bankAccDefault = _bankAcc[i];
			break;
		}
	}
}

void Account::setDefaultBankAcc(int index)
{
	_bankAccDefault = _bankAcc.at(index);
}

fstream& operator>>(fstream& in, Account& obj)
{
	in >> obj._login;
	in >> obj._password;
	return in;
}

fstream& operator<<(fstream& out, Account& obj) {
	out << obj._login << " ";
	out << obj._password << "\n";
	return out;
}

ifstream& operator>>(ifstream& in, Account& obj)
{
	in >> obj._login;
	in >> obj._password;
	return in;
}

ofstream& operator<<(ofstream& out, Account& obj) {
	out << obj._login << " ";
	out << obj._password << "\n";
	return out;
}

