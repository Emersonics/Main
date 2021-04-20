// GDPHYS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Assignments\MyVector.h"
#include "string.h"

int main()
{
    float x, y;
    std::cout << "1st Vector:" << std::endl;
    std::cin >> x; //cin class
    std::cin >> y;
    sample::MyVector sample1(x,y,0);
    std::cout << "2nd Vector:" << std::endl;
    std::cin >> x; //cin class
    std::cin >> y;
    sample::MyVector sample2(x,y,0);
    sample::MyVector tempVector(0,0,0); //temp
    
    //Output process
    std::cout << "(A+B): "; //addition
    printf("(%0.2f, %0.2f)\n", sample1.x + sample2.x, sample1.y + sample2.y);
    std::cout << "(A-B): "; //subtraction
    printf("(%0.2f, %0.2f)\n", sample1.x - sample2.x, sample1.y - sample2.y);
    std::cout << "(A*Bx): "; //scalar multiplication
    printf("(%0.2f, %0.2f)\n", sample1.x * sample2.x, sample1.y * sample2.x);
    std::cout << "(Component Product of A and B): "; //component product
    printf("(%0.2f, %0.2f)\n", tempVector.getComponentProduct(sample1, sample2).x, 
                             tempVector.getComponentProduct(sample1, sample2).y);
    std::cout << "(A.B): "; //scalar product
    printf("(%0.2f)\n", tempVector.getScalarProduct(sample1, sample2));
    std::cout << "(AxB): "; //vector product
    printf("(%0.2f, %0.2f, %0.2f)\n", tempVector.getVectorProduct(sample1, sample2).x,
                                   tempVector.getVectorProduct(sample1, sample2).y,
                                   tempVector.getVectorProduct(sample1, sample2).z);


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
