#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H

#include <vector>

using std::vector;

#include "Account.h"

class BankDatabase
{
	public:
		BankDatabase(); 
		
		bool authenticateUser( int, int ); 
		double getAvailableBalance( int ); 
		double getTotalBalance( int );
		void credit( int, double );
		void debit( int, double );
	private:
		vector< Account > accounts;

		Account * getAccount( int );
};

#endif
