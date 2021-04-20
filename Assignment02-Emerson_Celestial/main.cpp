// GDPHYS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Assignments\MyVector.h"
#include "string.h"
using namespace sample;

int main()
{
    float x, y;
    std::cin >> x;
    std::cin >> y;
    MyVector sample1(x,y);
    sample1.getDirection(sample1.getMagnitude());
    printf("Direction: (%f,%f)\n", sample1.getDirection(sample1.getMagnitude()).x, sample1.getDirection(sample1.getMagnitude()).y);
    std::cout << "Magnitude: " << sample1.getMagnitude()<<std::endl;
    system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
