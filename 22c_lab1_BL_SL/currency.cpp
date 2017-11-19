#include "currency.h"
#include <iostream>
#include <string>

using namespace std;

//******************************************************
// class constructor (no argument version)      
//******************************************************
Currency::Currency ()
{
	wholeName = "";
	whole = 0;
	fractional = 0;
	fractionalName = "";
}

//******************************************************
// class constructor    
//******************************************************
Currency::Currency (int initWhole, int initFractional)
{
	whole = initWhole;
	fractional = initFractional;
}

//******************************************************
// getAmount             
//
// returns the currrency whole and fractional as a 
// double
//******************************************************
double Currency::getAmount ()
{
	return whole + static_cast<double>(fractional) / fractionalPerWhole;
}

//******************************************************
// addInt           
//
// addition operator overloading for int
//******************************************************
void Currency::addInt (int addAmount)
{
	whole += addAmount;
}

// meant to be used by operator overloading
void Currency::addDouble (double addAmount)
{
	whole += addAmount;
	fractional += static_cast<int>(addAmount * fractionalPerWhole) % fractionalPerWhole;
	if (fractional >= fractionalPerWhole)
	{
		whole += fractional / fractionalPerWhole;
		fractional = fractional % fractionalPerWhole;
	}
}

// adding value by the whole and fractional numbers
void Currency::addValue (int wholeAdd, int fractionalAdd)
{
	whole += wholeAdd;
	fractional += fractionalAdd % fractionalPerWhole;
	whole += fractionalAdd / fractionalPerWhole;
	if (fractional >= fractionalPerWhole)
	{
		whole += fractional / fractionalPerWhole;
		fractional = fractional % fractionalPerWhole;
	}
}

//******************************************************
// setUp          
//
// this method is overriden in test for polymorphism
//******************************************************
void Currency::setUp ()
{
	wholeName = "Rupee";
	fractionalName = "Paise";
	fractionalPerWhole = 100;
}

/****************************
*********** GETTERS *********
*****************************/
string Currency::getWholeName ()
{
	return wholeName;
}

int Currency::getWhole ()
{
	return whole;
}

int Currency::getFractional ()
{
	return fractional;
}

string Currency::getFractionalName ()
{
	return fractionalName;
}

/*****************************************
*********** OPERATOR OVERLOADING *********
******************************************/
Currency::operator double ()
{
	return getAmount ();
}

Currency operator+(Currency &cM1, Currency &cM2)
{
	cM1.addDouble (cM2.getAmount ());
	return cM1;
}


Currency operator+(Currency &cM, int nValue)
{
	cM.addInt (nValue);
	return cM;
}

Currency operator+(int nValue, Currency &cM)
{
	// call operator+(Currency, nValue)
	return (cM + nValue);
}


Currency operator+(Currency &cM, double nValue)
{
	cM.addDouble (nValue);
	return cM;
}

Currency operator+(double nValue, Currency &cM)
{
	// call operator+(Currency, nValue)
	return (cM + nValue);
}

Currency operator+=(Currency &cM, double nValue)
{
	cM.addDouble (nValue);
	return cM;
}

ostream& operator<< (ostream &foo, Currency &cCurrency)
{
	// Since operator<< is a friend of the Currency class, we can access
	// Currency's members directly.
	foo << cCurrency.getWholeName () << ", " << cCurrency.getWhole ()
		<< ", " << cCurrency.getFractional () << ", " << cCurrency.getFractionalName ();
	return foo;
}