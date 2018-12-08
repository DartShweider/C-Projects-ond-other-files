#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <string>
#include <fstream> 
#include <iomanip> 
#include <cstring>
#include <vector>           
#include <sstream>          
#include <algorithm>    
#include "fstream.h"
#include <list>


int main()
{
    Storage stor_1;
    readDataBase("lib", &stor_1);
    stor_1.print();
    stor_1.remove("zzzzzzzzzzzzzzzzzzzzzzzzz");
    saveDataBase("lib", &stor_1);
    return 0;
}

