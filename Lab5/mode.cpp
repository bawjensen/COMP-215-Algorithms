#include "mode.h"

// ==================================================================
int compareMyType (const void* a, const void* b)
{
    long one = *(long*)a;  // cast void* pointer to a long* pointer, then dereference
    long two = *(long*)b;  // cast void* pointer to a long* pointer, then dereference
    
    // is one before two or not?
    if ( one <  two ) return -1;    // one before two, return negative
    if ( one == two ) return 0;     // one and two the same, return zero
    // else
    return 1;                       // otherwise two before one, return positive
} // end compareMyType()
// ==================================================================

// ==================================================================
void findMode_1(long Data[], long hmr, long& mode, long& times)
{
    // (1) sort the data
    qsort(Data, hmr, sizeof(long), compareMyType);
    
    /*for (long i=0; i < hmr; i++) {
     cout << "["<<i<<"]: " << Data[i] << endl;
     }*/
    
    // (2) now you find the longest "run"
    
    long currentNum = 0;
    long currentFrequency = 0;

    long mostFrequent = 0;
    long highestFrequency = 0;

    for (long i = 0; i < hmr; i++) {
        if (currentNum == Data[i]) {
            currentFrequency++;
        }
        else {
            currentNum = Data[i];
            currentFrequency = 1;
        }
        if (currentFrequency > highestFrequency) {
            highestFrequency = currentFrequency;
            mostFrequent = currentNum;
        }
    }
    
    
    mode   = mostFrequent;
    times  = highestFrequency;
    
    
} // end findMode1()


// ==================================================================
void findMode_2(long Data[], long hmr, const long MAX_RANDOM_VALUE, long& value, long& times)
{
    long h_Data[MAX_RANDOM_VALUE] = {};

    for (int i = 0; i < hmr; i++) {
        h_Data[Data[i]]++;
    }

    long mostFrequent = 0;
    long highestFrequency = 0;


    for (int i = 0; i < MAX_RANDOM_VALUE; i++) {
        if (h_Data[i] > mostFrequent) {
            mostFrequent = i;
            highestFrequency = h_Data[i];
        }
    }

    value = mostFrequent;
    times = highestFrequency;
    
} // end findMode_2()