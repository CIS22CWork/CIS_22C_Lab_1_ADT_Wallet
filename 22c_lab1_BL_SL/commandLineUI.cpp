/*
Branden Lee and Stephen Lee
CIS 22C
Fall 2017
Lab 1

Used Microsoft Visual Studio 2017

CommandLineUI class
contains the presentational and interactive interface in the command line for the user.
*/

#include <iostream>
#include "commandLineUI.h"

using namespace std;

CommandLineUI::CommandLineUI (Wallet *WalletObj)
{
	userWallet = WalletObj;
}

/* ******************** enterLoop ********************
the main menu UI loop
*/
void CommandLineUI::enterLoop ()
{
	cout << "Welcome to your wallet. ";
	bool loopActive = true;
	while (loopActive)
	{
		cout << "Please enter the number representing the menu options below:" << endl
			<< "1. Add a new currency to your wallet" << endl
			<< "2. Remove a currency from your wallet" << endl
			<< "3. Add value to a currency" << endl
			<< "4. List wallet contents" << endl
			<< "5. Empty wallet" << endl
			<< "6. Exit Application" << endl << endl
			<< "Selection Number: ";
		// there is a bug that when you enter "test,2,3,hey" in the menu selection. 
		// The program gets stuck in an infinite loop
		cin >> menuOption;
		cout << endl;
		if (menuOption < 1 || menuOption > 6)
		{
			cout << "Your selection was not valid. Please try again. ";
		}
		else
		{
			/* please keep each sub-menu in a separate function to increase readability and prevent
			a huge blob of unorganized code. */
			if (menuOption == 1)
			{
				addCurrency ();
			}
			else if (menuOption == 2)
			{
				removeCurrency ();
			}
			else if (menuOption == 3)
			{
				addValue ();
			}
			else if (menuOption == 4)
			{
				listContents ();
			}
			else if (menuOption == 5)
			{
				emptyWallet ();
			}
			else if (menuOption == 6)
			{
				loopActive = false;
			}
		}
	}
}

/* ******************** addCurrency ********************
adds a new currency type
*/
void CommandLineUI::addCurrency ()
{
	string inputString;
	string stringArray[4]; // the parsed sections of the user input string
	string stringPart;
	int success;
	cout << "You have chosen to add a new currency to your wallet." << endl
		 << " Please enter the name, whole value, and fractional value" << endl
		 << "i.e. Dollar, 3, 25" << endl;
	// grab string parts delimited by ','
	cin.ignore (numeric_limits<streamsize>::max (), '\n');
	getline (cin, inputString);
	int i = 0; // occurances of ','
	size_t pos = 0;
	while ((pos = inputString.find (',')) != std::string::npos)
	{
		stringArray[i] = inputString.substr (0, pos);
		inputString.erase (0, pos + 1);
		i++;
		cout << "*******************************************" << endl;
	}
	stringArray[2] = inputString;
	if (i != 2)
	{
		// no ',' found
		cout << endl << "ERROR: The inputed string is not in the correct format. You have used too many or too few commas." << endl << endl;
	}
	else
	{
		// convert whole and fractional strings to int
		stringstream wholeStream (stringArray[1]);
		int wholeAdd = 0;
		wholeStream >> wholeAdd;
		stringstream fractionalStream (stringArray[2]);
		int fractionalAdd = 0;
		fractionalStream >> fractionalAdd;
		success = userWallet->add (stringArray[0], wholeAdd, fractionalAdd);
		if (success >=0)
		{
			cout << "Add success!!" << endl << endl;
		}
		else
		{
			cout << "Add failed..." << endl << endl;
		}
	}
	cout << endl;
}

/* ******************** removeCurrency ********************
removes a new currency type
*/
void CommandLineUI::removeCurrency ()
{
	int currencyNumber;
	int currencyIndex;
	cout << "You have chosen to remove a currency. Please input the number representing the currency in your wallet." << endl;
	int n = userWallet->getCurrentSize ();
	/* uses overloaded subscript operator in Wallet */
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << &userWallet[i] << endl;
	}
	cout << endl << "currency number: ";
	cin >> currencyNumber;
	currencyIndex = currencyNumber - 1;
	try
	{
		if (userWallet->remove (currencyIndex))
		{
			cout << "Removal was a success!" << endl << endl;
		}
		else
		{
			cout << "Removal failed!" << endl << endl;
		}
	}
	catch (exception& e)
	{
		cout << "exception: " << e.what () << endl << endl;
	}
}

/* ******************** addValue ********************
prompts user to select the currency they wish to add value to, then prompts for the value to add.
adds value to the currency in the wallet.
*/
void CommandLineUI::addValue ()
{
	int addCurrencyNum;
	int addWholeValue;
	cout << "You have chosen to add value to a currency. Please input the number representing the currency in your wallet." << endl;
	int n = userWallet->getCurrentSize ();
	/* uses overloaded subscript operator in Wallet */
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << (*userWallet)[i] << endl;
	}
	cout << endl << "currency number: ";
	cin >> addCurrencyNum;
	int currencyIndex = addCurrencyNum - 1;
	if (addCurrencyNum - 1 < 0 || addCurrencyNum - 1 > n)
	{
		cout << "The currency number you entered was out of range." << endl;
	}
	else
	{
		cout << "What is the value you wish to add: ";
		cin >> addWholeValue;
		// operator overloading
		(*userWallet)[currencyIndex] += addWholeValue;
		cout << "You have added " << addWholeValue << " to currency #" << addCurrencyNum << endl << endl;
	}

}

/* ******************** listContents ********************
outputs the wallet contents to cout
keeps all cout streams in the CommandLineUI class.
*/
void CommandLineUI::listContents ()
{
	Currency temp;

	cout << "Here are the contents currently in your wallet:" << endl;
	int n = userWallet->getCurrentSize ();
	for (int i = 0; i < n; i++)
	{
		temp = (*userWallet)[i];
		cout << temp << endl;
	}
	cout << endl;
}

/* ******************** emptyWallet ********************
outputs the wallet contents to cout
keeps all cout streams in the CommandLineUI class.
*/
void CommandLineUI::emptyWallet ()
{
	char confirmChar;
	cout << "Are you sure you want to empty your wallet? This is not reversible." << endl
		<< "Y/N: ";
	cin >> confirmChar;
	cout << endl;
	if (confirmChar == 'Y' || confirmChar == 'y')
	{
		if (userWallet->clear ())
		{
			cout << "Your wallet has been emptied." << endl << endl;
		}
	}
}