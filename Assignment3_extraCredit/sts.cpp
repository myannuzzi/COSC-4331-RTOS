//sts.cpp
//C++ file to run sts algorithm
//Written by Mike Yannuzzi

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>

#define MAX_VOLTAGE = 1.0

using namespace std;

//Sporadic task struct
//A sporadic task is denoted by T = {a,c,d} where a is the arrival time, c is the computation time, and d is the deadline.
//The trask struct below follows the same convention.
struct task{
    int taskID;
    int a;
    int c;
    int d;
    int rc; // equivalent to the computation time - the time the task has been running
    double voltage;
};

//Compare two tasks by their arrival time for sorting
bool compareByArrivalTime(const task &a, const task &b){
    return a.a < b.a;
}

//Acceptance test - checks to see if the incoming task is accepted into the task set
void acceptanceTest(vector<task> taskSet, task newTask, int time){
    

}

//Sts Algorithm
void sts(int time, vector<task> tasks){
    cout << "Running sts at time: " << time << endl;
    //First check if the set is empty, if it is, break
    if(tasks.size() == 0){
        cout << "There are no more tasks to run..." << endl;
        return;
    }
    //Compute U_j(t) for all in task set
    for(int i=0;i<tasks.size();i++){
        if(tasks[i].a == time){
            cout << "task starting" << endl;
        }
    }
    
    //Compute U(t) and find k

    //Schedule only the tasks in [t, D_k] at the proper voltage and remove tasks from the set

    //let t=D_k

}

// Voltage value
double v = 0.0;

int main(){
    cout << "Running sts program..." << endl;
    //Create a vector of task structs
    vector<task> taskSet;
    priority_queue<task> runQueue;
    vector<task> completedTasks;
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
        //cout << line << endl;
        //Parse the line and turn it into a struct
        //Grab the task number
        string sub = line.substr(line.find("k ") + 1);
        task t;
        int currentTaskNum = stoi(sub);
        t.taskID = currentTaskNum;
        //cout << "The current task number is: " << currentTaskNum << endl;
        //Grab the []
        sub = line.substr(line.find("["), line.find("]"));
        //cout << sub << endl;
        //Remove the brackets
        //Tokenize by space
        sub.erase(0,1);
        sub.pop_back();
        //cout << sub << endl;
        stringstream ss(sub);
        string token;
        vector<int> vals;
        while(ss >> token){
            //cout << "Value is: " << token << endl;
            vals.push_back(stoi(token));
        }
        t.a = vals[0];
        t.c = vals[1];
        t.rc = vals[1];
        t.d = vals[2];
        t.voltage = 1.0;
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
    //Sort the task list
    sort(taskSet.begin(), taskSet.end(), compareByArrivalTime);
    cout << taskSet.size() << endl;
    //Print out the task set
    // for(int i=0;i<taskSet.size();i++){
    //     cout << "Task info: " << endl;
    //     cout << "Id: " << taskSet[i].taskID << endl;
    //     cout << "a: " << taskSet[i].a << endl;
    //     cout << "c: " << taskSet[i].c << endl;
    //     cout << "d: " << taskSet[i].d << endl; 
    // }
    //Run loop for 200 iterations
    int i=0;
    while(i<200){
        cout << "Simulation step: " << i << endl;

        //Run sts algorithm
        sts(i, taskSet);
        // //Check if a task is ready
        // for(int j=0;i<taskSet.size();j++){
        //     cout << j << endl;
        //     if(taskSet[j].a == i){
        //         cout << "TaskID: " << taskSet[j].taskID << " has arrived!" << endl;
        //     }
        // }
        i++;
    }
    cout << "Program finished. Printing out results..." << endl;
    //Print out results
    
}

