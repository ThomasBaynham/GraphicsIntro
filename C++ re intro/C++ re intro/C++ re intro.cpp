#include <iostream>
#include "RectangleCalculator.h"
#include "numberPicker.h"
#include "menuSystem.h"
#include "numberPrinter.h"

int main()
{
    /*RectangleCalculator* calcs = new RectangleCalculator;

    float height;
    std::cout << "input rectangle height: ";
    std::cin >> height;

    float width;
    std::cout << "input rectangle width: ";
    std::cin >> width;

    float area = calcs->rectangleArea(height, width);
    float perim = calcs->rectanglePerimeter(height, width);

    delete calcs;

    std::cout << "Ahe area of the rectangle is: " << area << "\nAnd the perimeter is" << perim;*/

    /*numberPicker* picker = new numberPicker;

    nums numbers;
    numbers = picker->userInputs();

    int theBiggest = picker->numberSelector(numbers);
    std::cout << "The largest is " << theBiggest;*/

    //menuSystem* weather = new menuSystem;

    //weather->weatherMenu();

    numberPrinter* print = new numberPrinter;

    print->numberPrint();


}


