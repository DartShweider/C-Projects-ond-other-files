#include <iostream>
#include <stdio.h>
#include <math.h>

void inputData(float* inputDataArray)
{
    float a, b, c;
    
        
    std::cout<< "Уравнение вида ax^2 + bx + c = 0. Введите параметры a, b, c. " << std::endl;
    std::cout<< "Параметр а: ";
    std::cin >> a;
    std::cout<< "Параметр b: ";
    std::cin >> b;
    std::cout<< "Параметр c: ";
    std::cin >> c;
    inputDataArray[0] = a;
    inputDataArray[1] = b;
    inputDataArray[2] = c;
}

void solutionOfEquation(float* inputDataArray, float* rootsInformation)
{
    float conditional_zero = 0.00001;
    int numberOfRoots = 0;
    float a = inputDataArray[0];
    float b = inputDataArray[1];
    float c = inputDataArray[2];
        
        if (abs(a) > conditional_zero and abs(b) > conditional_zero and abs(c) > conditional_zero)
        {
            float d = pow(b, 2) - 4*a*c;
            
            if (d > conditional_zero) 
            {
                rootsInformation[0] = (-b - sqrt(d))/(2*a);
                rootsInformation[1] = (-b + sqrt(d))/(2*a);
                numberOfRoots = 2;
                
            } else if (abs(d) <= conditional_zero) 
            {
                rootsInformation[0] = -b/2;
                numberOfRoots = 1;
                
            } else if (d < -conditional_zero)
            {
                numberOfRoots = 0;
            }
            
        } else if (abs(a) < conditional_zero and abs(b) > conditional_zero) 
        {
            rootsInformation[0] = -c/b;
            numberOfRoots = 1;   
            
        }  else if (abs(b) < conditional_zero and abs(a) < conditional_zero) 
        {
            numberOfRoots = 0;
        }
        rootsInformation[2] = numberOfRoots;
    
}

void outputValues(float* rootsInformation)
{
    if (rootsInformation[2] > 0)
    {
       std::cout << "Корни уравнения:" << std::endl;
        for (int i = 0; i < rootsInformation[2]; i++)
        {
         std::cout<< rootsInformation[i] << "   "<<std::endl;
        } 
    } else
    {
        std::cout<< "Действительных корней нет"<< std::endl;
        
    }
    
}

int main()
{
        float inputDataArray[3] = {0,0,0};
        float rootsInformation[3] = {0, 0, 0};
        inputData(inputDataArray);
        solutionOfEquation(inputDataArray, rootsInformation);
        outputValues(rootsInformation);
        return 0;
}
