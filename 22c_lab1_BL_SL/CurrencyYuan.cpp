#include "currency.h"
#include "CurrencyYuan.h"

//******************************************************
// class constructor            
//******************************************************
CurrencyYuan::CurrencyYuan(int initWhole, int initFractional) : Currency(initWhole, initFractional)
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
void CurrencyYuan::setUp()
{
	wholeName = "Yuan";
	fractionalName = "Fen";
	fractionalPerWhole = 100;
}