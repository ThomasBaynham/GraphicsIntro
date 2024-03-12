#include <iostream>
#include "numberPicker.h"



int numberPicker::numberSelector(nums numbers)
{
	int largest = 0;
	for (int num : numbers.tenNum)
	{
		if (num > largest) {
			largest = num;
		}
	}
	return largest;
}

nums numberPicker::userInputs()
{
	nums userInput;
	for (int i = 0; i < 10; i++) {
		std::cout << "input a number:";
		std::cin >> userInput.tenNum[i];
	}
	return userInput;
}
