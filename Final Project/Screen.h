#ifndef SCREEN_H
#define SCREEN_H

#include <string>

using std::string;

class Screen
{
	public:
		void displayMessage( string ) const; 
		void displayMessageLine( string ) const; 
		void displayDollarAmount( double ) const; 
};

#endif
