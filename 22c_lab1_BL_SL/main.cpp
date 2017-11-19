/*
Branden Lee and Stephen Lee
CIS 22C
Fall 2017
Lab 1

Used Microsoft Visual Studio 2017

main
the entry point for the application. from here we create an instance of the wallet 
and pass it to the UI class that will handle the rest of the app.
All constants and settings are set here to encourage module independence.
*/

#include <iostream>
#include "currency.h"
#include "commandLineUI.h"
#include "Wallet.h"
using namespace std;

int main ()
{
	// initialize the constants for the wallet
	const int CURRENCY_MAX = 5;
	Wallet userWallet(CURRENCY_MAX);
	CommandLineUI UI(&userWallet);
	// start the UI
	UI.enterLoop ();

	//comment out the next line before compiling final .exe and submitting to the teacher
	system ("pause");
	return 0;
}
// hello world