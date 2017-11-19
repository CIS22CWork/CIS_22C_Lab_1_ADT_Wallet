#include <iostream>
#include <string>

#ifndef CURR_EURO_H
#define CURR_EURO_H
class CurrencyEuro : public Currency
{
private:
	int created = false;
public:
	CurrencyEuro (int initWhole, int initFractional);
	void setUp();
};
#endif