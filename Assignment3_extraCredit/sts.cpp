//sts.cpp
//C++ file to run sts algorithm
//Written by Mike Yannuzzi

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//Sporadic task struct
//A sporadic task is denoted by T = {a,c,d} where a is the arrival time, c is the computation time, and d is the deadline.
//The trask struct below follows the same convention.
struct task{
    int taskID;
    int a;
    int c;
    int d;
};

int main(){
    cout << "Running sts program..." << endl;
    //Create a vector of task structs
    vector<task> taskSet;
    //Read in data file
    ifstream fp("input.txt");
    string line;
    //Grab the number of tasks
    getline(fp, line);
    string sub = line.substr(line.find(":") + 1);
    //cout << sub << endl;
    int taskNum = stoi(sub);
    cout << "Number of tasks is: " << taskNum << endl;
    while(getline(fp, line)){
        cout << line << endl;
        //Parse the line and turn it into a struct
        //Grab the task number
        string sub = line.substr(line.find("k ") + 1);
        int currentTaskNum = stoi(sub);
        cout << "The current task number is: " << currentTaskNum << endl;
        //Grab the []
        sub = line.substr(line.find("["), line.find("]"));
        cout << sub << endl;
    }

    //Run loop for 200 iterations
    for(int i=0;i<200;i++){
        cout << "Simulation step: " << i << endl;
    }
    cout << "Program finished. Printing out results..." << endl;
    //Print out results
    
}