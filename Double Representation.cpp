#include <stdint.h>
#include <iostream>

int main()
{
    uint64_t x;

    x = 0xc048d00000000000;
    double* y = (double*)&x;
    //std::cout << *y << std::endl;
    //std::cout << (double*)&x << std::endl;
    //std::cout << *(double*)&(0xc048d00000000000) << std::endl;
    return 0;
}