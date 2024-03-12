#include <iostream>
#include "menuSystem.h"

void menuSystem::weatherMenu()
{
	int userInput;
	bool continueLoop = true;

	while (continueLoop == true) {
		std::cout << "\nPlease choose an option: \n1. Sunny \n2. Cloudy \n3. Raining \n4. Exit\n";
		std::cin >> userInput;

		if (userInput == 1) {
			std::cout << "you should eat ice cream";
		}
		else if (userInput == 2) {
			std::cout << "you should eat sweets";
		}
		else if (userInput == 3) {
			std::cout << "you should eat pie";
		}
		else if (userInput == 4) {
			continueLoop = false;
		}
	}
}
