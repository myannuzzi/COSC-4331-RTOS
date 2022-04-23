//sts.cpp
//C++ file to run sts algorithm
//Written by Mike Yannuzzi

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
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
        task t;
        int currentTaskNum = stoi(sub);
        t.taskID = currentTaskNum;
        cout << "The current task number is: " << currentTaskNum << endl;
        //Grab the []
        sub = line.substr(line.find("["), line.find("]"));
        //cout << sub << endl;
        //Remove the brackets
        //Tokenize by space
        sub.erase(0,1);
        sub.pop_back();
        cout << sub << endl;
        stringstream ss(sub);
        string token;
        vector<int> vals;
        while(ss >> token){
            cout << "Value is: " << token << endl;
            vals.push_back(stoi(token));
        }
        t.a = vals[0];
        t.c = vals[1];
        t.d = vals[2];
        taskSet.push_back(t);
    }

    //Print out the task set
    for(int i=0;i<taskSet.size();i++){
        cout << "Task info: " << endl;
        cout << "Id: " << taskSet[i].taskID << endl;
        cout << "a: " << taskSet[i].a << endl;
        cout << "c: " << taskSet[i].c << endl;
        cout << "d: " << taskSet[i].d << endl; 
    }

    //Run loop for 200 iterations
    for(int i=0;i<200;i++){
        //cout << "Simulation step: " << i << endl;
    }
    cout << "Program finished. Printing out results..." << endl;
    //Print out results
    
}