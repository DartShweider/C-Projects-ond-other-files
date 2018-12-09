#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <string>
#include <fstream> 
#include <iomanip> 
#include <cstring>   
#include <list>

#include "storage.h"
#include "fstream.h"
#include "HashFunc2.h"

int main()
{
    Storage<std::string> stor_1(400);
    readDataBase("lib", &stor_1);
    stor_1.print();
    saveDataBase("lib", &stor_1);
    return 0;
}

