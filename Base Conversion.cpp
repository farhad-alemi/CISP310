#include <iostream>
#include <cmath>
#include <vector>

int main()
{
    int inputNumber;
           int inputBase,
           outputBase;
           //outputNumber;
    int    numDigit = 0;
    std::vector<int> v, v10;

    std::cout << "Input Number: ";
    std::cin >> inputNumber;
    std::cout << "Input Base [2-10]: ";
    std::cin >> inputBase;
    std::cout << "Output Base: ";
    std::cin >> outputBase;

    while (inputNumber >= pow(inputBase, numDigit))
    {
        numDigit++;
    }

    // conversion to base 10
    for (int i = 0; i < numDigits; i++)
    {
        
    }

    for (int i = 0; i < 9; i++)
    {
        v.push_back((inputNumber / static_cast<int>(pow(outputBase, i))) % outputBase);
    }
    
    for (int i = 8; i >= 0; i--)
    {
        std::cout << v.at(i);
    }
}