#include <stdio.h>      // printf(), easy scientific notation
#include <iostream>     // cout, etc.
#include <fstream>      // for opening ifstream and ofstream objects for FILES

#include "IO.h"
#include "mode.h"


// ========================================================
void printMenu()
{
    cout << "------------------------------" << endl;
    cout << "  1: Create Random Data File" << endl;
    cout << "  2: Read Random Data File" << endl;
    cout << "  3: Find Mode (v1)" << endl;
    cout << "  4: Find Mode (v2)" << endl;
    cout << "  5: EXIT" << endl;
    cout << "------------------------------" << endl;
} // printMenu()


// ========================================================
void menuIO(const long MAX_ARRAY_SIZE, const long MAX_RANDOM_VALUE)
{
    bool done = false;
    short choice;
    
    string filename;
        
    long Data[MAX_ARRAY_SIZE];
    long hmr = 0;
    
    while (!done)
    {
        printMenu();
        cout << "Enter your choice: ";
        cin  >> choice;
        
        //----------------------------------------------
        if (choice == 1) {
            cout << "Enter filename (don't include a file extension):";
            cin >> filename;
            makeRandomDataFile( filename, MAX_ARRAY_SIZE, MAX_RANDOM_VALUE );
        } //(1) -----------------------------------------
        
        else if (choice == 2) {
            cout << "Enter filename (include file extension):";
            cin >> filename;
            readDataFile(filename, Data, hmr);
            cout << "Ok, successfully read " << hmr << " data values." << endl;
            
            /*for (long i=0; i < hmr; i++) {
                cout << "["<<i<<"]: " << Data[i] << endl;
            }*/
        } //(2) -----------------------------------------
        
        else if (choice == 3) {
            
         if (hmr > 0) {
            long mode, value;
            
            clock_t start, stop;        // need time.h
            
            start = clock();
            
            findMode_1(Data, hmr, value, mode);
            
            stop = clock();
            
            double duration = (double) (stop - start) / CLOCKS_PER_SEC;
            
            printf("\nIt took %1.3e seconds to find the mode in %ld random long integers.\n", duration, hmr);
            
            cout << endl << "VALUE of: " << value << " has a MODE of: " << mode << endl;
         }
         else
             cout << "No Data read in; Read in a data file first." << endl;
            
        } //(3) -----------------------------------------
        
        else if (choice == 4) {
            
         if (hmr > 0) {
            long times, value;
            
            clock_t start, stop;        // need time.h
            
            start = clock();
            
            findMode_2(Data, hmr, MAX_RANDOM_VALUE, value, times);
            
            stop = clock();
            
            double duration = (double) (stop - start) / CLOCKS_PER_SEC;
            
            printf("\nIt took %1.3e seconds to find the mode in %ld random long integers.\n", duration, hmr);
            
            cout << endl << "VALUE of: " << value << " has a MODE of: " << times << endl;
         }
         else
             cout << "No Data read in; Read in a data file first." << endl;
            

        } // (4)-----------------------------------------

        else if (choice == 5) {
            cout << endl << "Goodbye." << endl;
            done = true;
        } // (5)-----------------------------------------
        
        else {
            cout << "Invalid input choice of " << choice << endl;
        } // (bogus input)-----------------------------------------
  
    } // while more choices made
    
} // end menuIO()




// ========================================================
void makeRandomDataFile(string filename, const long MAX_ARRAY_SIZE, const long MAX_RANDOM_VALUE )
{
    // tack on .tsv since we'll make this a Tab Separated Value file
    string outFile = filename + ".tsv";
    
	ofstream fout;				// stream to connect to output file
	
    cout << "Creating output file: " << outFile.c_str() << endl << endl;
    
    // NOTE!! C++ open() method does *not* take a string; so convert to old school C-style string
	fout.open( outFile.c_str() );
	
	if ( fout.fail() )	// but did the attempt to open fail?
	{
		cout << "ERROR: file called " << outFile << " did NOT open." << endl;
		exit(-1);
	} // if
    
    long N;
    cout << "How many random integers between 1 and 10 should be generated (maximum of "
         << MAX_ARRAY_SIZE << "): ";
    cin >> N;
    
    if (N > MAX_ARRAY_SIZE) {
        cout << "Sorry; that's too many; using the MAX of: " << MAX_ARRAY_SIZE << endl;
        N = MAX_ARRAY_SIZE;
    }
    
    short N_PER_LINE = 20;
    char TAB = '\t';
    short line = 0;
    
    for(long i=0; i < N; i++)
    {
        short n = rand() % MAX_RANDOM_VALUE + 1;   // 1 to MAX_RANDOM_VALUE
        fout << n << TAB;
        line++;
        if (line % N_PER_LINE == 0)
        {
            fout << endl;
            line = 0;
        }
    }
    
    fout.close();

} // end makeRandomDataFile()


// ========================================================
void readDataFile(string filename, long Data[], long& hmr)
{
    string inFile = filename + ".tsv";

    ifstream fin;

    cout << "Opening input file: " << inFile.c_str() << endl << endl;

    fin.open( inFile.c_str() );

    if (fin.fail()) {
        cout << "ERROR: file called " << inFile << " did NOT open." << endl;
    }

    long x;
    fin >> x;

    while (fin) {
        Data[hmr] = x;
        fin >> x;
        hmr++;
    }
}