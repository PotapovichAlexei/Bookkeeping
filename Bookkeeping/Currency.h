#pragma once
#include "Header.h"

class Currency
{
private:
	float _cCurr;	//coefficient of curency
	float _vCurr;	//value of curency
	string _tCurr;	//type of curency
public:
	Currency(): _cCurr(0), _vCurr(0), _tCurr("") {};
	Currency(const Currency& obj);
	Currency(string t, float v, float c) : _cCurr(c), _vCurr(v), _tCurr(t) {};
	~Currency() {};

	float getCCurr() { return this->_cCurr; }
	void setCCurr(float cCur) { this->_cCurr = cCur; }
	float getVCurr() { return this->_vCurr; }
	void setVCurr(float vCurr) { this->_vCurr = vCurr; }
	string getTCurr() { return this->_tCurr; }
	void setTCurr(string tCurr) { this->_tCurr = tCurr; }
	
	friend fstream& operator>>(fstream& in, Currency& obj);
	friend fstream& operator<<(fstream& out, Currency& obj);
	friend ifstream& operator>>(ifstream& in, Currency& obj);
	friend ofstream& operator<<(ofstream& out, Currency& obj);

	friend ostream& operator<<(ostream& out, Currency& obj);
	friend istream& operator>>(istream& out, Currency& obj);

	void displayShow();

	const bool operator==(Currency& obj);

};

