//#include "Date.h"
//#include "Exception.h"
#include"Header.h"

istream& operator>>(istream& in, Date& obj)
{
    do {

        cout << "Enter date (dd.mm.yyyy): ";
        int* date = new int[3];
        date = inputDate();
        obj._day = date[0];
        obj._month = date[1];
        obj._year = date[2];
    } while (!obj.valid());

return in;
}

ostream& operator<<(ostream& out, Date& obj) {
	out <<setw(2) <<  obj._day << "." << setw(2) << obj._month << "." << setw(4) << obj._year ;
	
	return out;
}

Date::Date(const Date& date)
{
	this->_day = date._day;
	this->_month = date._month;
	this->_year= date._year;
}

bool Date::valid() const {
    // This function will check the given date is valid or not.
    // If the date is not valid then it will return the value false.
    // Need some more checks on the year, though
    if (_year < 0) return false;
    if (_month > 12 || _month < 1) return false;
    if (_day > 31 || _day < 1) return false;
    if ((_day == 31 &&
        (_month == 2 || _month == 4 || _month == 6 || _month == 9 || _month == 11)))
        return false;
    if (_day == 30 && _month == 2) return false;
        if ((_day == 29 && _month == 2) && !((_year) % 4 == 0)) return false;
    return true;
};

bool operator == (const Date& d1, const Date& d2) {
    // check for equality
  //  if (!d1.valid()) { return false; };
  //  if (!d2.valid()) { return false; };
    if ((d1.getDay() == d2.getDay())
        && (d1.getMonth() == d2.getMonth())
        && (d1.getYear() == d2.getYear())) {
        return true;
    };
    return false;
}

bool operator !=(const Date& d1, const Date& d2) {
    return !(d1 == d2);
}
bool operator < (const Date& d1, const Date& d2) {
   // if (!d1.valid()) { return false; }; // not meaningful, return anything
   // if (!d2.valid()) { return false; }; // should really be an exception, but ?
    if (d1.getYear() < d2.getYear()) { return true; }
    else if (d1.getYear() > d2.getYear()) { return false; }
    else { // same year
        if (d1.getMonth() < d2.getMonth()) { return true; }
        else if (d1.getMonth() > d2.getMonth()) { return false; }
        else { // same month
            if (d1.getDay() < d2.getDay()) { return true; }
            else { return false; }
        };
    };
    return false;
};
bool operator > (const Date& d1, const Date& d2) {
    if (d1 == d2) { return false; }; // this is strict inequality
    if (d1 < d2) { return false; };
    return true;
}
bool operator <=(const Date& d1, const Date& d2) {
    if (d1 == d2) { return true; }
    return (d1 < d2);
}
bool operator >=(const Date& d1, const Date& d2) {
    if (d1 == d2) { return true; };
    return (d1 > d2);
}

int Date::dayInMonth()
{
    if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
        return 31;
    else if (_month != 2)
        return 30;
    else if (_month == 2 && _year % 4 == 0) {
        return 29;
    }
    else return 28;
}

Date operator+(const Date& d1, const Date& d2)
{
    Date help;

    help.setYear(d1.getYear() + d2.getYear());
    if (d1.getMonth() + d2.getMonth() > 12) {
        help.setYear(help.getYear() + 1);
        help.setMonth(d1.getMonth() + d2.getMonth() - 12);
    }
    else  help.setMonth(d1.getMonth() + d2.getMonth());

    if (d1.getDay() + d2.getDay() > help.dayInMonth()) {
        if (help.getMonth() + 1 > 12) {
            help.setYear(help.getYear() + 1);
            help.setMonth(help.getMonth() - 11);
            help.setDay(d1.getDay() + d2.getDay());
        }
        else  help.setMonth(d1.getMonth() + d2.getMonth() - help.dayInMonth());
    }
    else help.setDay(d1.getDay() + d2.getDay());


    return help;
}

fstream& operator>>(fstream& in, Date& obj)
{
    in >> obj._day;
    in >> obj._month;
    in >> obj._year;

    return in;
}

fstream& operator<<(fstream& out, Date& obj) {
    out << obj._day << " ";
    out << obj._month << " ";
    out << obj._year << " ";
    return out;
}

ifstream& operator>>(ifstream& in, Date& obj)
{
    in >> obj._day;
    in >> obj._month;
    in >> obj._year;

    return in;
}

ofstream& operator<<(ofstream& out, Date& obj) {
    out << obj._day << " ";
    out << obj._month << " ";
    out << obj._year << " ";
    return out;
}