#pragma once
#ifndef APPLICATION_H_
#define APPLICATION_H_
#include <string>
#include "DataBaseArray.cpp"
#include "Interface.h"


struct MainProgram
{
    
    dataBaseArray dataStorage;
    MainProgramInterface Interface;
    void startTheProgram();
    void showMenu();
/*    void getDBInfo();
    void addPatient();
    */
    void Exit();/*
    void saveDataBase();
    void getDBNames();*/
    void readDataBase();

    void addDataBase();
    
};




/////------------------/////
/////------------------/////






void MainProgram::showMenu()
{
    Interface.showMenu();
    
}

/*
void MainProgram::getDBInfo()
{
        Interface.getDBInfo();
        std::string NameOfDB;
        std::cin>>NameOfDB;
        dataStorage.getInfo(NameOfDB); 
    
}


void MainProgram::addPatient()
{
    
        dataStorage.showNamesOfDBs();
        Interface.addPatient(1);
        std::string NameOfDB;
        std::cin>>NameOfDB;
        Interface.addPatient(2);
        dataStorage.addPatient(NameOfDB);
        Interface.addPatient(3);

    
}

*/
void MainProgram::Exit()
{
    
        Interface.Exit();
    
}

/*
void MainProgram::saveDataBase()
{
    
        Interface.saveDataBase(1);
        std::string NameOfDB;
        std::cin >> NameOfDB;
        
        Interface.saveDataBase(2);
        
        dataStorage.saveDataBase(NameOfDB);
        Interface.saveDataBase(3);
                    
}


void MainProgram::readDataBase()
{
    
        std::string NameOfDB;
        Interface.readDataBase(1);
        std::cin>> NameOfDB;
        std::cout<<"\n";
        dataStorage.readDataBase(NameOfDB);
        Interface.readDataBase(2);
    
}


void MainProgram::getDBNames()
{

         dataStorage.showNamesOfDBs();

}

*/
void MainProgram::addDataBase()
{
        Interface.addDataBase(1);
        std::string NameOfDB;
        std::cin >> NameOfDB;
        dataStorage.addDataBase(NameOfDB);
        Interface.addDataBase(2);

}


void MainProgram::startTheProgram()
{
    int choise = -1;
        
        while (choise != 0)
        {
            
            showMenu();
            std::cin >> choise;
            
            switch(choise)
            {
/*                case 1:
                {
                    getDBInfo();
                    continue;
                }*/
                case 0:
                {
                    
                    Exit();
                    break;
                    
                }
/*                case 2:
                {
                    addPatient();
                    continue;
                }
                case 3:
                {
                    saveDataBase();
                    continue;
                    
                }
                case 4:
                {
                    readDataBase();
                    continue;
                    
                }
                
                case 5:
                {
                    getDBNames();
                    continue;
                }*/
                case 6:
                {
                    addDataBase();
                    continue;
                }
                default: break;
                
            }
            
        }
    
}



#endif
