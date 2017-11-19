#include <sstream>
#include <limits>
#include "Wallet.h"
class CommandLineUI
{
private:
	Wallet *userWallet;
	int menuOption;
	int currentMenu;
public:
	CommandLineUI(Wallet *WalletObj);
	void enterLoop();
	void addCurrency();
	void removeCurrency ();
	void addValue();
	void listContents();
	void emptyWallet();
};