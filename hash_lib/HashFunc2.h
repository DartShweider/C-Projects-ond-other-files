#pragma once

#include <string>
#include <vector>
#include <list>


std::string itos(int n)
{
   const int max_size = std::numeric_limits<int>::digits10 + 1 /*sign*/ + 1 /*0-terminator*/;
   char buffer[max_size] = {0};
   sprintf(buffer, "%d", n);
   return std::string(buffer);
}




template <class Type>
int comp_hash(Type data)
{
    long long int sum = 0;
    for (int i = 0; i < data.length(); i++)
    {
        sum += pow((int)(data[i])+ pow(i,4), 1.90);
        sum -= ((int)(data[i]) - 65) * (i + 1000)*i;
        //std::cout << sum << std::endl;
        
        
    }
    
    return (int)sum;
    
} 
