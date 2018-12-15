#pragma once
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <string>
#include <fstream> 
#include <iomanip> 
#include <cstring>   
#include <list>

template<typename Type>
int comp_hash(Type data)
{
    std::stringstream sstr;
    std::string str;
    sstr << data;
    sstr >> str;
    long long int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        sum += pow((int)(str[i])+ pow(i,4), 1.90);
        sum -= ((int)(str[i]) - 65) * (i + 1000)*i;
        //std::cout << sum << std::endl;
    }
    return (int)sum;
    
} 
