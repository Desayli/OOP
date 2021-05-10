#include "Deposit.h" 
#include "Screen.h"
#include "BankDatabase.h" 
#include "Keypad.h"
#include "DepositSlot.h" 

const static int CANCELED = 0;

Deposit::Deposit( int userAccountNumber, Screen &atmScreen, BankDatabase &atmBankDatabase, Keypad &atmKeypad, DepositSlot &atmDepositSlot )
: Transaction( userAccountNumber, atmScreen, atmBankDatabase ), keypad( atmKeypad ), depositSlot( atmDepositSlot )
{

}

void Deposit::execute()
{
	BankDatabase &bankDatabase = getBankDatabase();
	Screen &screen = getScreen();

	amount = promptForDepositAmount();

	if ( amount != CANCELED )
	{
		screen.displayMessage("Please insert a deposit envelope containing " );
		screen.displayDollarAmount( amount );
		screen.displayMessageLine( " in the deposit slot." );

		bool envelopeReceived = depositSlot.isEnvelopeReceived();

		if ( envelopeReceived )
		{
			screen.displayMessageLine( "Your envelope has been received."
			"NOTE: The money just will not be available until we"
			"verify the amount of any enclosed cash, and any enclosed "
			"checks clear." );

			bankDatabase.credit( getAccountNumber(), amount );
		} 
		else 
		{
			screen.displayMessageLine( "You did not insert an "
			"envelope, so the ATM has canceled your transaction." );
		}
	} 
	
	else 
	{
		screen.displayMessageLine( "Canceling transaction..." );
	}
}

double Deposit::promptForDepositAmount() const
{
	Screen &screen = getScreen();

	screen.displayMessage( "Please enter a deposit amount in "
	"CENTS (or 0 to cancel): " );
	int input = keypad.getInput();

	if ( input == CANCELED )
	return CANCELED;
	else
	{
		return static_cast< double >( input ) / 100;
	}
}

