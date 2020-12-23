#include "Header.h"
#include "Currency.h"

fstream& operator>>(fstream& in, Currency& obj)
{
	in >> obj._cCurr;
	in >> obj._tCurr;
	in >> obj._vCurr;
	return in;
}

fstream& operator<<(fstream& out, Currency& obj) {
	out << obj._cCurr << " ";
	out << obj._tCurr << "\n";
	out << obj._vCurr << "\n";
	return out;
}

ifstream& operator>>(ifstream& in, Currency& obj)
{
	in >> obj._cCurr;
	in >> obj._tCurr;
	in >> obj._vCurr;
	return in;
}

ofstream& operator<<(ofstream& out, Currency& obj) {
	out << obj._cCurr << " ";
	out << obj._tCurr << " ";
	out << obj._vCurr << "\n";
	return out;
}


ostream& operator<<(ostream& out, Currency& obj)
{
	
	out << "|" << setw(10) << obj._tCurr << "|" << setw(10) << obj._vCurr << "|" << setw(11) << obj._cCurr << '|';
	
	return out;
}

istream& operator>>(istream& in, Currency& obj)
{
	cout << "Type: ";
	obj._tCurr = inputString(4);

	cout << "Coefficient: ";
	obj._cCurr= inputFloatWS();

	cout << "Value: ";
	obj._vCurr = inputFloatWS();

	return in;
}


void Currency::displayShow()
{
	cout << "|"; for (int i = 0; i < 33; i++) cout << "~"; cout << "|" << endl;
	cout << "|" << setw(10) << "Type " << "|" << setw(10) << "Value " << "|" << setw(10) << "Coefficient" << "|" << endl;
	cout << "|"; for (int i = 0; i < 33; i++) cout << "~"; cout << "|" << endl;
}


Currency::Currency(const Currency& obj)
{
	_cCurr = obj._cCurr;
	_vCurr = obj._vCurr;
	_tCurr = obj._tCurr;
}

const bool Currency::operator==(Currency& obj)
{
	if (_cCurr == obj._cCurr && _vCurr == obj._vCurr && _tCurr == obj._tCurr)
		return true;
	return false;
}
