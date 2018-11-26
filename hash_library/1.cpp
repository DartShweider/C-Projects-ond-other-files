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
#include <iterator>

int main()
{
    Storage stor_1;
    stor_1.setHashValue();
    stor_1.readDataBase();
    stor_1.readBook();
    return 0;
}
