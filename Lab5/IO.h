#ifndef IO
#define IO

#include <iostream>

#include <time.h>       // for clock_t type and clock() function
#include <limits.h>     // for CLOCKS_PER_SEC  (clock ticks per second)

using namespace std;

// function declaration prototypes
void printMenu();
void menuIO(const long, const long);

void makeRandomDataFile(string, const long, const long);
void readDataFile (string, long [], long&);

#endif 