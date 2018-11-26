#pragma once
#ifndef BOOK_H_
#define BOOK_H_
#include <string>
#include <fstream>




struct Book
{
    
    std::string name;
    void loadBook();
    std::string data = "Empty";
    
    
}; 

void Book::loadBook()
{
    std::ifstream book_data(this->name);
    std::string Big_data = "";
    
    while(book_data)
    {
        std::string str;
        std::getline(book_data, str);
        if (str != "") // Это непонятная магия, без которой прога не рабоатет.
        {
            Big_data += str;
            Big_data += "\n";
        }
    }
    this->data = Big_data;

}





#endif
