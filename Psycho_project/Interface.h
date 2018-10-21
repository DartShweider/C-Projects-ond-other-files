#pragma once
#ifndef INTERFACE_H_
#define INTERFACE_H_
#include <string>


struct MainProgramInterface
{
    
    void showMenu();
    void getDBInfo();
    void addPatient(int number);
    void Exit();
    void saveDataBase(int number);
    void readDataBase(int number);
    void addDataBase(int number);
    
};


void MainProgramInterface::showMenu()
{
    
        std::cout<<"___________________________________________________ \n";
        std::cout<<" Приложение для мониторинга пациентов психушки.\n";
        std::cout<<"___________________________________________________ \n";
        std::cout<<"Для вывода списка данных пациентов введите (1).\n";
        std::cout<<"Для добавления пациента в список введите (2).\n";
        std::cout<<"Для сохранения изменений введите (3).\n";
        std::cout<<"Для загрузки базы данных введите (4).\n";
        std::cout<<"Для вывода имён загруженных баз данных введите (5).\n";
        std::cout<<"Для создания новой базы данных введите (6).\n";
        std::cout<<"Для выхода из программы введите (0)";
        std::cout<< "\n";
        std::cout<<"___________________________________________________ \n";
    
}


void MainProgramInterface::getDBInfo()
{
    
        std::cout<<"Введите имя базы данных, список которой хотите получить:  \n";
    
}


void MainProgramInterface::addPatient(int number)
{
    switch(number)
    {
        case 1:
            std::cout<<"Введите имя базы данных, в которую хотите добавить психа \n";
            
        case 2:
            std::cout<<"___________________________________________________ \n";
            std::cout<< "Введите имя и фамилию психа \n";
            std::cout<<"___________________________________________________ \n";
        
        case 3:
            std::cout<<"___________________________________________________ \n";
            std::cout<<"Псих успешно внесён в базу данных \n";
            std::cout<<"___________________________________________________ \n";
        
        
    }
    
}


void MainProgramInterface::Exit()
{
    
        std::cout<<"___________________________________________________ \n";
        std::cout << "Exit" << std::endl;
        std::cout<<"___________________________________________________ \n";
    
}


void MainProgramInterface::saveDataBase(int number)
{
    switch(number)
    {
        case 1:
            std::cout<<"Введите имя базы данных, которую хотите сохранить \n";
            
        case 2:
            std::cout<<"___________________________________________________ \n";
            std::cout<<"Введите имя файла, в который вы хотите сохранить \n";
            std::cout<<"___________________________________________________ \n";
            
        case 3:
            std::cout<<"___________________________________________________ \n";
            std::cout<<"Данные успешно сохранены \n";
                
    }
    
}


void MainProgramInterface::readDataBase(int number)
{
    
    
    switch(number)
    {
        case 1:
            std::cout<<"___________________________________________________ \n";
            std::cout<<"Введите имя файла, который хотите загрузить \n";
            std::cout<<"___________________________________________________ \n";   
            
        case 2:
            std::cout<<"___________________________________________________ \n";
            std::cout<<"Файл успешно загружен \n";
            std::cout<<"___________________________________________________ \n";
        
    }

    
}


void MainProgramInterface::addDataBase(int number)
{
    
    
    switch(number)
    {
        case 1:
            std::cout<<"___________________________________________________ \n";
            std::cout<<"Введите имя новой базы данных \n";
            std::cout<<"___________________________________________________ \n";   
            
        case 2:
            std::cout<<"___________________________________________________ \n";
            std::cout<<"База данных успешно создана \n";
            std::cout<<"___________________________________________________ \n";
        
    }

    
}







#endif
