/*
Branden Lee and Stephen Lee
CIS 22C
Fall 2017
Lab 1

Used Microsoft Visual Studio 2017

Wallet class
This is our ADT bag. It manages the Currency and currency children classes forming our wallet.
Responsibilites:
-Get the number of items currently in the bag
-See whether the bag is empty
-Add a given object to the bag
-remove an occurrence of a specific object from the bag, if possible
-remove all objects from the bag
-count the number of times a certain object occurs in the bag
-Test whether the bag contains a particular object
-Look at all objects that are in the bag
*/

#include "Wallet.h"
#include <iostream>
#include <string>
using namespace std;

Wallet::Wallet (const int CURRENCY_MAX)
{
	currencyTypesNum = 0; //current number of currencies in the currencyObjs array
	currencyMax = CURRENCY_MAX;
	currencyObjs = new Currency*[currencyMax];
}

/* ******************** getCurrentSize ********************
get current number of currency types in the wallet
*/
int Wallet::getCurrentSize ()
{
	return currencyTypesNum;
}

/* ******************** isEmpty ********************
is the wallet empty?
*/
bool Wallet::isEmpty ()
{
	if (currencyTypesNum > 0)
	{
		return false;
	}
	return true;
}

/* ******************** add ********************
adds a new currency type to the wallet
return: the currencyIndex for the new currency type. -1 means there is no more space.
*/
int Wallet::add (std::string wholeName, int whole, int fractional)
{
	int currencyIndex = -1;
	if (currencyTypesNum < currencyMax)
	{
		currencyIndex = currencyTypesNum;
		// since the assignment requirement is to create derived classes of currency we have to match the text input to the correct derived class
		if (wholeName == "Dollar")
		{
			currencyObjs[currencyIndex] = new CurrencyDollar (whole, fractional);
		}
		else if (wholeName == "Euro")
		{
			currencyObjs[currencyIndex] = new CurrencyEuro (whole, fractional);
		}
		else if (wholeName == "Rupee")
		{
			currencyObjs[currencyIndex] = new CurrencyRupee(whole, fractional);
		}
		else if (wholeName == "Yen")
		{
			currencyObjs[currencyIndex] = new CurrencyYen(whole, fractional);
		}
		else if (wholeName == "Yuan")
		{
			currencyObjs[currencyIndex] = new CurrencyYuan(whole, fractional);
		}
		else
		{
			currencyTypesNum--;
			currencyIndex = -2;
		}
		currencyTypesNum++;
	}
	return currencyIndex;
}

/* ******************** remove ********************
removes a specific currency type from the wallet
*/
bool Wallet::remove (int currencyIndex)
{
	if (exist (currencyIndex))
	{
		// shifts each index down one
		for (int i = currencyIndex; i < currencyTypesNum - 1; i++)
		{
			currencyObjs[i] = currencyObjs[i + 1];
		}
		currencyObjs[currencyTypesNum - 1] = NULL;
		currencyTypesNum--;
		return true;
	}
	return false;
}
/* ******************** addValue ********************
adds whole and fractional integers to the currency type
*/
bool Wallet::addValue (int currencyIndex, int wholeAdd, int fractionalAdd)
{
	if (exist (currencyIndex))
	{
		currencyObjs[currencyIndex]->addValue (wholeAdd, fractionalAdd);
		return true;
	}
}
/* ******************** removeValue ********************
removes whole and fractional integers to the currency type
*/
bool Wallet::removeValue (int currencyIndex, int wholeAdd, int fractionalAdd)
{
	if (exist (currencyIndex))
	{
		currencyObjs[currencyIndex]->addValue (-wholeAdd, -fractionalAdd);
		return true;
	}
}

/* ******************** clear ********************
removes all currency types from the wallet
*/
bool Wallet::clear ()
{
	for (int i = 0; i < 10; i++)
	{
		currencyObjs[i] = NULL;
	}
	currencyTypesNum = 0;
	return true;
}

/* ******************** contains ********************
finds the currency name in the wallet
*/
bool Wallet::contains (std::string wholeNameFind)
{
	for (int i = 0; i < currencyTypesNum; i++)
	{
		if (currencyObjs[i]->getWholeName () == wholeNameFind)
		{
			return true;
		}
	}
	return false;
}

/* ******************** exist ********************
determines if the currency index exists
*/
bool Wallet::exist (int currencyIndex)
{
	if (currencyIndex >= 0 && currencyIndex < currencyTypesNum)
	{
		return true;
	}
	return false;
}

Currency Wallet::operator[] (const unsigned int i)
{
	return (*currencyObjs)[i];
}