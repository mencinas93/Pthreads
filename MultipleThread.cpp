#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <pthread.h>

using namespace std;


const int MAX_NUMBERS = 100000;
const int MAX_THREADS = 20;
const int NUMBERS_PER_THREAD = 5000;

int numbers[MAX_NUMBERS]; //array of intergers read from file
int sums[MAX_THREADS] = {0}; // array of intergers that each thread will use to sum a portion of the numbers.
int thread_index = 0; // keeps track of the thread currently indexed on.


void* Sum_Runner(void* arg)
{
    int my_index = thread_index++;

        int start_index = my_index * NUMBERS_PER_THREAD;
        int end_index = (my_index + 1) * NUMBERS_PER_THREAD;
        //keeps track of the thread min and max and its sum.
        for (int i = start_index; i < end_index; i++) {
            sums[my_index] += numbers[i];
        }

        return NULL;
    }
    
    
    
    




int main() {
    ifstream iFile;
    
    iFile.open("input.txt");
    if(!iFile.is_open()){
        cout << "Not inputting file!\n";
    }
    string line;
    //create string so i can place integers inside line by line.
    int index = 0; // index counter
    while(getline(iFile, line)){
        numbers[index] = stoi(line);
        index++;
        // array created to place integers inside a interger array.
    }
    iFile.close();
    
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++){
        pthread_create(&threads[i], NULL, Sum_Runner, NULL);
    }
    for (int i = 0; i < MAX_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    
    int total_SUM = 0;
    for (int i = 0; i < MAX_THREADS; i++){
        total_SUM += sums[i];
    }
    
    cout << "Total Sum is " << total_SUM << endl;
    
    return 0;
}
