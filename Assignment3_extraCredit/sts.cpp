//sts.cpp
//C++ file to run sts algorithm
//Written by Mike Yannuzzi

#include <iostream>
#include <vector>

using namespace std;

//Sporadic task struct
//A sporadic task is denoted by T = {a,c,d} where a is the arrival time, c is the computation time, and d is the deadline.
//The trask struct below follows the same convention.
struct {
    int taskID;
    int a;
    int c;
    int d;
} task;

int main(){
    cout << "Running sts program..." << endl;
    //Create a vector of task structs
    vector<task> taskSet;
    //Read in data file

    //Run loop for 200 iterations
    for(int i=0;i<200;i++){
        cout << "Simulation step: " << i << endl;
    }
    cout << "Program finished. Printing out results..." << endl;
    //Print out results
    
}