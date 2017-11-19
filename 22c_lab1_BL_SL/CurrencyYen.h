#include <iostream>
#include <string>

#ifndef CURR_YEN_H
#define CURR_YEN_H
class CurrencyYen : public Currency
{
private:
	int created = false;
public:
	CurrencyYen(int initWhole, int initFractional);
	void setUp();
};
#endif