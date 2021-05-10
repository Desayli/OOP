#include <iostream>
using std::cin;

#include "Keypad.h"

int Keypad::getInput() const
{
	int input;
 	cin >> input;
 	return input; 
}
