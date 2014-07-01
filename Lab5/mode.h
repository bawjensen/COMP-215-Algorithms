#ifndef MODE
#define MODE

#include <iostream>
#include <stdlib.h>     // qsort()

using namespace std;

int compareMyType (const void* a, const void* b);

void findMode_1(long Data[], long hmr, long& mode, long& times);

void findMode_2(long Data[], long hmr, const long MAX_RANDOM_VALUE, long& mode, long& times);

#endif /* MODE */