 #pragma once
#ifndef PATIENTS_H_
#define PATIENTS_H_
#include <string>
#include "List.h"



struct Patient     
{
    
    std::string name = " ";
    std::string surname = " ";
    bool sex = true;
    int age = 0;
    std::string city = " ";
    int visitAmount = 0;
    
}; 


struct DataBase      
{
    

    std::string nameOfDB = " ";
    int capacity = 1;
    int numberOfPatients = 0;
    List<Patient> patients;
    
    
};


#endif
