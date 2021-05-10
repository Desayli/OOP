#include "Withdrawal.h" 
#include "Screen.h" 
#include "BankDatabase.h" 
#include "Keypad.h"
#include "CashDispenser.h"

const static int CANCELED = 6;

Withdrawal::Withdrawal( int userAccountNumber, Screen &atmScreen, BankDatabase &atmBankDatabase, Keypad &atmKeypad, CashDispenser &atmCashDispenser )
: Transaction( userAccountNumber, atmScreen, atmBankDatabase ), keypad( atmKeypad ), cashDispenser( atmCashDispenser )
{

} 

void Withdrawal::execute()
{
	bool cashDispensed = false; 
	bool transactionCanceled = false; 
	BankDatabase &bankDatabase = getBankDatabase();
	Screen &screen = getScreen();

	do
	{
		int selection = displayMenuOfAmounts();

		if ( selection != CANCELED )
		{
			amount = selection;
			double availableBalance = bankDatabase.getAvailableBalance( getAccountNumber() );

			if ( amount <= availableBalance )
			{
				if ( cashDispenser.isSufficientCashAvailable( amount ) )
				{
					bankDatabase.debit( getAccountNumber(), amount );

					cashDispenser.dispenseCash( amount );
					cashDispensed = true; 

					screen.displayMessageLine("Please take your cash from the cash dispenser." );
				}
			else 
			screen.displayMessageLine("Insufficient cash available in the ATM. Please choose a smaller amount." );
			} 
		else 
			{
				screen.displayMessageLine("Insufficient funds in your account. Please choose a smaller amount." );
			}
		}
	else
	{
		screen.displayMessageLine( "Canceling transaction..." );
		transactionCanceled = true;
	} 
	} while ( !cashDispensed && !transactionCanceled ); 
} 


int Withdrawal::displayMenuOfAmounts() const
{
	int userChoice = 0; 

	Screen &screen = getScreen();

	int amounts[] = { 0, 20, 40, 60, 100, 200 };

	while ( userChoice == 0 )
{
screen.displayMessageLine( "Withdrawal options:" );
screen.displayMessageLine( "1 - $20" );
screen.displayMessageLine( "2 - $40" );
screen.displayMessageLine( "3 - $60" );
screen.displayMessageLine( "4 - $100" );
screen.displayMessageLine( "5 - $200" );
screen.displayMessageLine( "6 - Cancel transaction" );
screen.displayMessage( "Choose a withdrawal option (1-6): " );

int input = keypad.getInput();

switch ( input )
{
	case 1:
	case 2: 
	case 3:
	case 4:
	case 5:
	userChoice = amounts[ input ]; 
	break;
	case CANCELED: 
	userChoice = CANCELED; 
	break;
	default: 
	screen.displayMessageLine("Ivalid selection. Try again." );
} 
} 

return userChoice; 
}
