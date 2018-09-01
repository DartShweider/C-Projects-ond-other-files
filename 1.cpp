#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
        
        float a, b, c;
        std::cout<< "Уравнение вида ax^2 + bx + c = 0. Введите параметры a, b, c. " << std::endl;
        std::cout<< "Параметр а: ";
        std::cin >> a;
        std::cout<< "Параметр b: ";
        std::cin >> b;
        std::cout<< "Параметр c: ";
        std::cin >> c;
        
        float d = pow(b, 2) - 4*a*c;
        std::cout <<"Дискриминант: " << d << std::endl;
        if (d > 0) {
            std::cout<< "Корень_1: "<< (-b - sqrt(d))/(2*a)<< "  " << "Корень_2: " << (-b + sqrt(d))/(2*a) << std::endl;
        } else if (d == 0) {
            std::cout<< "Корень: "<< -b/2 << std::endl;
        } else {
            std::cout<< "Действительных корней нет" << std::endl;
        }
        return 0;
}
