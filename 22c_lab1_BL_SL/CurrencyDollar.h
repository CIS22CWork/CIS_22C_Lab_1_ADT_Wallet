#include <iostream>
#include <string>

#ifndef CURR_DOLLAR_H
#define CURR_DOLLAR_H
class CurrencyDollar : public Currency
{
private:
	int created = false;
public:
	CurrencyDollar (int initWhole, int initFractional);
	void setUp();
};
#endif