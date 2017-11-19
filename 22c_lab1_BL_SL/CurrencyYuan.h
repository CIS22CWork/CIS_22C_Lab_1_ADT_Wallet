#include <iostream>
#include <string>

#ifndef CURR_YUAN_H
#define CURR_YUAN_H
class CurrencyYuan : public Currency
{
private:
	int created = false;
public:
	CurrencyYuan(int initWhole, int initFractional);
	void setUp();
};
#endif