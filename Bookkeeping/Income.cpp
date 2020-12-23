//#include "Income.h"
#include "Header.h"
//#include "Exception.h"

istream& operator>>(istream& in, Income& obj)
{
	//rewind(stdin);
	//in >> obj._date;
	in >> dynamic_cast<Transaction&> (obj);
	rewind(stdin);
	cout << "Source: ";
	obj._source = inputString(15);

	return in;
}	

ostream& operator<<(ostream& out, Income& obj) {
	out << dynamic_cast<Transaction&> (obj) << setw(11) << obj._dirtyMoney << "|" << setw(11) << obj._source << "|";

	return out;
}

fstream& operator>>(fstream& in, Income& obj)
{
	in >> dynamic_cast<Transaction&> (obj);
	in >> obj._source;
	return in;
}

fstream& operator<<(fstream& out, Income& obj) {
	out << dynamic_cast<Transaction&> (obj);
	out << obj._source << " ";
	return out;
}

ifstream& operator>>(ifstream& in, Income& obj)
{
	in >> dynamic_cast<Transaction&> (obj);
	in >> obj._source;
	return in;
}

ofstream& operator<<(ofstream& out, Income& obj) {
	out << dynamic_cast<Transaction&> (obj);
	out << obj._source << " ";
	return out;
}