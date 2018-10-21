#include "Patients.h"
#include <string>



void split(const std::string &s, char delim, std::vector<std::string> &elems)
{

    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}
//
//
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}





void DataBase::addPatient(std::string name, std::string surname)
{

    Patient patient;
    patient.name = name;
    patient.surname = surname;
    patients.push_back(patient);
    
}


void DataBase::deletePatient(std::string name, std::string surname)
{
    
    int patientIndex = DataBase::findPatient(name, surname);
    patients.delete_elem(patientIndex);
    
}


int DataBase::findPatient(std::string name, std::string surname)
{
    
    Node<Patient>* current = patients.head;
    int index;
        for (int i = 0; i < patients.capacity; i++)
        {

            if (current->value.name == name and current->value.surname == surname)
            {
                index = i;
            }
            current = current->next;
            
        }
    return index;
    
}


void DataBase::emptyBase()
{
    
    patients.empty();
    
}


void DataBase::readDataBase(std::string filename)
{
    
    std::ifstream DATABASE(filename);
    nameOfDB = filename;
    while(DATABASE)
    {
        
        std::string str;
        std::getline(DATABASE, str);
        
        if (str != "") // Это непонятная магия, без которой прога не рабоатет.
        {
            
            std::vector<std::string> patientData;
            Patient patient;
            patientData = split(str, ' ');
            patient.name = patientData[0];
            patient.surname = patientData[1];
            patients.push_back(patient);
            
        }
        
    }
    
    
}


void DataBase::saveDataBase(std::string filename)
{
    
    std::ofstream DATABASE(filename);
    
    Node<Patient>* current = patients.head;
    
    for (int i = 0; i < patients.capacity; i++)
    {
        
        DATABASE<< current->value.name <<" "<< current->value.surname<<"\n";
        if (i < patients.capacity - 1)
        {
            current = current->next;
        }

        
    }
    DATABASE.close();
    
    
}

void DataBase::printPatients()
{
    
    Node<Patient>* current = patients.head;
    
    for (int currentId = 0; currentId < patients.capacity; currentId++)
            {
                std::cout<<"(" << currentId + 1 << ")  ";
                std::cout<< current->value.name << "   ";
                std::cout<< current->value.surname << "   ";
                std::cout<< "\n";
                /*std::cout<< database->patients[currentId].sex << "   ";
                //std::cout<< database->patients[currentId].age << "   ";
                //std::cout<< database->patients[currentId].city << "   ";
                */
                std::cout<< /*current->value.visitAmount*/"" << "   " << std::endl; 
                if (currentId < patients.capacity - 1)
                {
                    current = current->next;
                }
            }
    
    std::cout<<"Кол-во психов:  "<< patients.capacity << "\n";
    
    
}



