
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <pthread.h>

using namespace std;
/*
 
 1.    File input.txt contains 100,000 numbers separated by new line. Do the following:
 1.1    Write a C++ program to compute the summation of these 100,000 numbers using single thread.
 1.2    Write a C++ program to compute the summation of these 100,000 numbers using 20 threads, meaning each thread compute 5000 summations and the main thread sum the result of the 20 threads.
 1.3    Using the time syscall to compare the time spent for 1.1 and 1.2

 Turn Ins:

 Source code of two programs and a short report on to answer the following question:
 1.    What is the run time for 1.1?
 2.    What is the run time for 1.2?
 3.    Is there a run time difference and why?

 */
const int MAX_NUMBERS = 100000;

int numbers_array[MAX_NUMBERS];


int main() {
    ifstream iFile;
    
    iFile.open("input.txt");
    if(!iFile.is_open()){
        cout << "Not inputting file!\n";
    }
    int sum = 0;
    string line;
    int i = 0;
    //create string so i can place integers inside line by line.
    while(getline(iFile, line)){
        numbers_array[i] = stoi(line);
        i++;
       
     //   cout << "Sum for input files is " << sum << endl;
        //     cout << " " << line;
    }
    for (int i = 0; i < MAX_NUMBERS; i++){
        sum += numbers_array[i];
    }
    cout << "Sum for input files is " << sum << endl;
    iFile.close();
    return 0;
}
