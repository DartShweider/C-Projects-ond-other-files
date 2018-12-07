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
#include "storage.h"
#include <list>


int main()
{
    Storage stor_1;
    stor_1.readDataBase();
    
    //stor_1.add("Devastator");
    //stor_1.saveDataBase();
    stor_1.delete_d("Devastator");
    stor_1.saveDataBase();
    return 0;
}

