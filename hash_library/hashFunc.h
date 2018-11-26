#pragma once
#ifndef HASHFUNC_H_
#define HASHFUNC_H_
#include <string>






std::string itos(int n)
{
   const int max_size = std::numeric_limits<int>::digits10 + 1 /*sign*/ + 1 /*0-terminator*/;
   char buffer[max_size] = {0};
   sprintf(buffer, "%d", n);
   return std::string(buffer);
}



std::string comp_hash(std::string book_name)
{
    std::string hash = "";
    float elem_1 = 0;
    for (int i =0; i < book_name.length(); i++)
    {
        elem_1 = pow((int)(book_name[i]), 3);
        elem_1 = sqrt(elem_1);
        elem_1 = (int) elem_1;
        elem_1 = (elem_1 - 13) - (int)(book_name[i]) % 10;
        hash += itos(elem_1);
        
    }
    
    return hash;
    
} 




#endif
