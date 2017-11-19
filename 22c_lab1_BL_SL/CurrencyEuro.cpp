#include "currency.h"
#include "CurrencyEuro.h"

//******************************************************
// class constructor            
//******************************************************
CurrencyEuro::CurrencyEuro (int initWhole, int initFractional) : Currency (initWhole, initFractional)
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
void CurrencyEuro::setUp() {
	wholeName = "Euro";
	fractionalName = "Cent";
	fractionalPerWhole = 100;
}