#include <iostream>
#include <string>

#ifndef CURRENCY_H
#define CURRENCY_H
class Currency
{
protected:
	int whole;
	std::string wholeName;
	int fractional;
	std::string fractionalName;
	int fractionalPerWhole;
public:
	Currency::Currency();
	Currency::Currency(int initWhole, int initFractional);
	double getAmount();
	void addInt(int addAmount);
	void addDouble(double addAmount);
	void addValue(int wholeAdd, int fractionalAdd);
	virtual void setUp();

	std::string getWholeName();
	int Currency::getWhole();
	int Currency::getFractional();
	std::string Currency::getFractionalName();

	operator double();
	// Currency + Currency
	friend Currency operator+(const Currency &cM1, const Currency &cM2);
	// Currency + int
	friend Currency operator+(const Currency &cM, int nValue);
	friend Currency operator+(int nValue, const Currency &cM);
	// Currency + double
	friend Currency operator+(Currency &cM, double nValue);
	friend Currency operator+(double nValue, Currency &cM);
	friend Currency operator+=(Currency &cM, double nValue);

	// cout << Currency
    friend std::ostream& operator<< (std::ostream &foo, Currency &cCurrency);
};
#endif