#pragma once
#include "Header.h"
class Date {
private:
    int _day;
    int _month;
    int _year;

public:
    Date() : _day(0), _month(0), _year(0) {};
    Date(int day, int month, int year) : _day(day), _month(month), _year(year) {};
    Date(const Date& date);
    bool valid() const;

   int getDay()const { return _day; };
   int getMonth()const { return _month; }
   int getYear()const { return _year; }
   void setDay(const int& day) { _day = day; }
   void setMonth(const int& month) { _month = month; }
   void setYear(const int& year) { _year = year; }

   friend bool operator== (const Date&, const Date&); // comparison operators
   friend bool operator!= (const Date&, const Date&);
   friend bool operator< (const Date&, const Date&);
   friend bool operator> (const Date&, const Date&);
   friend bool operator<= (const Date&, const Date&);
   friend bool operator>= (const Date&, const Date&);
   friend Date operator+ (const Date&, const Date&);
   int dayInMonth();
    friend istream& operator>>(istream& in, Date& obj);
    friend ostream& operator<<(ostream& out, Date& obj);

    friend fstream& operator>>(fstream& in, Date& obj);
    friend fstream& operator<<(fstream& out, Date& obj);
    friend ifstream& operator>>(ifstream& in, Date& obj);
    friend ofstream& operator<<(ofstream& out, Date& obj);
};

//ostream& operator<<(ostream& out, const Date& dt) {
//    string m[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
//    out << dt._day << "." << m[dt._month - 1] << "." << dt._year;
//    return out;
//}
