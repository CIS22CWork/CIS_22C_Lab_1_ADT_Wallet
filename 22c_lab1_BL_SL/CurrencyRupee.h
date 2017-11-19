#include <iostream>
#include <string>

#ifndef CURR_RUPEE_H
#define CURR_RUPEE_H
class CurrencyRupee : public Currency
{
private:
	int created = false;
public:
	CurrencyRupee(int initWhole, int initFractional);
	void setUp();
};
#endif