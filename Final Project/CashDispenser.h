#ifndef CASH_DISPENSER_H
#define CASH_DISPENSER_H

class CashDispenser
{
	public:
		CashDispenser();
		void dispenseCash( int );
		bool isSufficientCashAvailable( int ) const;
	
	private:
		const static int INITIAL_COUNT = 500;
		int count; 
}; 

#endif 

