#include "numberPrinter.h"
#include <iostream>

void numberPrinter::numberPrint()
{
	std::cout << "please input a number:";
	int num;
	std::cin >> num;

	for (int i = 1; i <= num+1; i++) {
		for (int n = 1; n < i; n++) {
			std::cout << n <<" ";
		}
		std::cout << "\n";
	}
}
