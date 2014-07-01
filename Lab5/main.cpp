#include <fstream>
#include <iostream>

#include "IO.h"

using namespace std;

int main()
{
    // bounds on generating MAX_ARRAY_SIZE values in the range from [1..MAX_RANDOM_VALUE]
    
    const long MAX_ARRAY_SIZE   = 1000000;  // max array size
    
    const long MAX_RANDOM_VALUE = 10;   // random values: [1..MAX_RANDOM_VALUE]

    
    // do all the work from the menuIO function
    menuIO(MAX_ARRAY_SIZE, MAX_RANDOM_VALUE);

    cout << "\n\nDone.\n\n";
    
    return 0;
}