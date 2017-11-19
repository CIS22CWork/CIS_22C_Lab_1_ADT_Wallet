#include "currency.h"
#include "CurrencyDollar.h"

//******************************************************
// class constructor            
//******************************************************
CurrencyDollar::CurrencyDollar (int initWhole, int initFractional) : Currency (initWhole, initFractional)
{
	setUp();
}

//******************************************************
// setUp             
//
// This is a demonstration of polymorphism.
// This function is not necessary since the variables 
// could be defined in the constructor, but the 
// instrutions say we need to demonstrate polymorphism        
//******************************************************
void CurrencyDollar::setUp() {
	wholeName = "Dollar";
	fractionalName = "Cents";
	fractionalPerWhole = 100;
}