#include "ATM.h"
#include "Transaction.h"
#include "BalanceInquiry.h"
#include "Withdrawal.h" 
#include "Deposit.h" 


enum MenuOption { BALANCE_INQUIRY = 1, WITHDRAWAL, DEPOSIT, EXIT };


ATM::ATM() 
: userAuthenticated ( false ), currentAccountNumber( 0 ) 
{

} 


void ATM::run() {
while ( true ) {
while ( !userAuthenticated ) {
screen.displayMessageLine( "Welcome!" );
authenticateUser(); 
} 

performTransactions(); 
userAuthenticated = false; 
currentAccountNumber = 0; 
screen.displayMessageLine( "Thank you! Goodbye!" );
}
}

void ATM::authenticateUser() {
screen.displayMessage( "Please enter your account number: " );
int accountNumber = keypad.getInput(); 
screen.displayMessage( "Enter your PIN: " );
int pin = keypad.getInput(); 

userAuthenticated = bankDatabase.authenticateUser( accountNumber, pin );
	if ( userAuthenticated ) {
currentAccountNumber = accountNumber;
} 
	else screen.displayMessageLine("Invalid account number or PIN. Please try again." );
}

void ATM::performTransactions() {

Transaction *currentTransactionPtr;
bool userExited = false;
	while ( !userExited ) {

int mainMenuSelection = displayMainMenu();


switch ( mainMenuSelection ) {
case BALANCE_INQUIRY:
case WITHDRAWAL:
case DEPOSIT:
	

currentTransactionPtr = createTransaction( mainMenuSelection );
currentTransactionPtr->execute();
delete currentTransactionPtr;
break;
case EXIT:
screen.displayMessageLine( "Exiting the system..." );
userExited = true;
break;
default: 
screen.displayMessageLine("You did not enter a valid selection. Try again." );
break;
} 
}
}

int ATM::displayMainMenu() const {
screen.displayMessageLine( "Main menu:" );
screen.displayMessageLine( "1 - View my balance" );
screen.displayMessageLine( "2 - Withdraw cash" );
screen.displayMessageLine( "3 - Deposit funds" );
screen.displayMessageLine( "4 - Exit" );
screen.displayMessage( "Enter a choice: " );
return keypad.getInput(); 
} 

Transaction *ATM::createTransaction( int type ) {
Transaction *tempPtr;
	switch ( type ) {
case BALANCE_INQUIRY: 
tempPtr = new BalanceInquiry(currentAccountNumber, screen, bankDatabase );
break;

case WITHDRAWAL:
tempPtr = new Withdrawal( currentAccountNumber, screen,
bankDatabase, keypad, cashDispenser );
break;

case DEPOSIT:
tempPtr = new Deposit( currentAccountNumber, screen,
bankDatabase, keypad, depositSlot );
break;
}

return tempPtr; 
}
