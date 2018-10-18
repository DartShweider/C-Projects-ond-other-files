#pragma once
#ifndef MAINPROCESS_H_
#define MAINPROCESS_H_
#include <string>
#include "DataBaseArray.h"



struct MainProgram
{
    
    dataBaseArray dbArray;
    void startTheProgram();
    void showMenu();
    void getDBInfo();
    void addPatient();
    void Exit();
    void saveDataBase();
    void loadDataBase();
    void getDBNames();
    
    
};




/////------------------/////
/////------------------/////






void MainProgram::showMenu()
{
    
        std::cout<<"___________________________________________________ \n";
        std::cout<<" Приложение для мониторинга пациентов психушки.\n";
        std::cout<<"___________________________________________________ \n";
        std::cout<<"Для вывода списка данных пациентов введите (1).\n";
        std::cout<<"Для добавления пациента в список введите (2).\n";
        std::cout<<"Для сохранения изменений введите (3).\n";
        std::cout<<"Для загрузки базы данных введите (4).\n";
        std::cout<<"Для вывода имён загруженных баз данных введите (5).\n";
        std::cout<<"Для выхода из программы введите (0)"  << std::endl;
        std::cout<<"___________________________________________________ \n";
    
}


void MainProgram::getDBInfo()
{
        std::cout<<"Введите имя базы данных, список которой хотите получить:  \n";
        std::string NameOfDB;
        std::cin>>NameOfDB;
        dbArray.getInfo(NameOfDB); 
    
}


void MainProgram::addPatient()
{
    
        dbArray.showNamesOfDBs();
        std::cout<<"Введите имя базы данных, в которую хотите добавить психа \n";
        std::string NameOfDB;
        std::cin>>NameOfDB;
        std::cout<<"___________________________________________________ \n";
        std::cout<< "Введите имя и фамилию психа \n";
        std::cout<<"___________________________________________________ \n";
        std::string name;
        std::string surname;
        std::cin>> name;
        std::cin>> surname;
        dbArray.addPatient(NameOfDB, name, surname);
        std::cout<<"___________________________________________________ \n";
        std::cout<<"Псих успешно внесён в базу данных \n";
        std::cout<<"___________________________________________________ \n";

    
}


void MainProgram::Exit()
{
    
        std::cout<<"___________________________________________________ \n";
        std::cout << "Exit" << std::endl;
        std::cout<<"___________________________________________________ \n";
    
}


void MainProgram::saveDataBase()
{
    
        std::cout<<"Введите имя базы данных, которую хотите сохранить \n";
        std::string NameOfDB;
        std::cin>>NameOfDB;
        std::string filename;
        std::cout<<"___________________________________________________ \n";
        std::cout<<"Введите имя файла, в который вы хотите сохранить \n";
        std::cout<<"___________________________________________________ \n";
        std::cin>>filename;
        std::cout<<"\n";
        dbArray.saveDataBase(filename, NameOfDB);
        std::cout<<"___________________________________________________ \n";
        std::cout<<"Данные успешно сохранены \n";
        std::cout<<"___________________________________________________ \n";
                    
                    
}


void MainProgram::loadDataBase()
{
    
        std::string filename;
        std::cout<<"___________________________________________________ \n";
        std::cout<<"Введите имя файла, который хотите загрузить \n";
        std::cout<<"___________________________________________________ \n";
        std::cin>>filename;
        std::cout<<"\n";
        dbArray.readDataBase(filename);
        std::cout<<"___________________________________________________ \n";
        std::cout<<"Файл успешно загружен \n";
        std::cout<<"___________________________________________________ \n";
    
}


void MainProgram::getDBNames()
{

         dbArray.showNamesOfDBs();

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
                case 1:
                {
                    getDBInfo();
                    continue;
                }
                case 0:
                {
                    
                    Exit();
                    break;
                    
                }
                case 2:
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
                    loadDataBase();
                    continue;
                    
                }
                case 5:
                {
                    getDBNames();
                    continue;
                }
                default: break;
                
            }
            
        }
    
}



#endif
