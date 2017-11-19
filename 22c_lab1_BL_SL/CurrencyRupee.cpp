#include "currency.h"
#include "CurrencyRupee.h"

//******************************************************
// class constructor            
//******************************************************
CurrencyRupee::CurrencyRupee(int initWhole, int initFractional) : Currency(initWhole, initFractional)
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
void CurrencyRupee::setUp()
{
	wholeName = "Rupee";
	fractionalName = "Paise";
	fractionalPerWhole = 100;
}