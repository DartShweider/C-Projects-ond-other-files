 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <fstream> // работа с файлами
#include <iomanip> // манипуляторы ввода/вывода
#include <cstring>
#include <vector>           // std::(vector)
#include <sstream>          // std::(istringstream)
#include <algorithm>        // std::(copy)
#include <cassert>

#define ASSERT_EQUALL assert(abs(a-b) <= 0.0000001) ; std::cout << a << std::endl << b << std::endl;
#define ASSERT_NEQUALL assert(abs(a-b) >=0.0000001) ; std::cout << a << std::endl << b << std::endl;
#define ASSERT_TRUE assert(a) ; std::cout << a << std::endl;
#define ASSERT_FALSE assert(!a) ; std::cout << a << std::endl;

bool assert_equal(float a,float b)
{
    
    
    float conditional_zero = 0.00000001;
    a = b-a;
    if (abs(a) <= conditional_zero)
        return true;
    else
        return false;
    
}

bool assert_nequal(float a,float b)
{
    
    
    float conditional_zero = 0.00000001;
    a = b-a;
    if (abs(a) > conditional_zero)
        return true;
    else
        return false;
    
}


int main()
{
   int a, b;
   std::cin>>a;
   std::cin>>b;
   
    //std::cout << assert_equal(a, b) << std::endl;
    //std::cout << assert_nequal(a, b) << std::endl;
    ASSERT_EQUALL(a, b);
    ASSERT_NEQUALL(a, b);
    return 0;
}
