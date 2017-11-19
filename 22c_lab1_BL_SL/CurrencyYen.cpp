#include "currency.h"
#include "CurrencyYen.h"

//******************************************************
// class constructor            
//******************************************************
CurrencyYen::CurrencyYen(int initWhole, int initFractional) : Currency(initWhole, initFractional)
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
void CurrencyYen::setUp()
{
	wholeName = "Yen";
	fractionalName = "Sen";
	fractionalPerWhole = 100;
}