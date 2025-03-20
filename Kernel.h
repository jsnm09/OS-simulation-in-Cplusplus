#ifndef KERNEL_H
#define KERNEL_H
#include <iostream>
#include <vector>
#include <queue>
#include "Process.h"
#include "Schedule.h"
#include <unistd.h>
#include <string>

using namespace std;

class Kernel{
private:
vector<Process> processes;
queue<Process> readyQueue;
queue<Process> waitingQueue;
Schedule scheduler;
public:
void start(){
cout << "Starting JamOS...\n";
sleep(5);
}
void loggin(){
    cout << "Logging in as guest\n";
sleep(5);
}

void addProcess(const Process& process){
    processes.push_back(process);
    readyQueue.push(process);
    cout << "Process added: " << process.getProcessID() << 
    " with burst cycle: " << process.getBurstCycle() << endl;
}

void scheduleProcesses(int totalCycleCount) {
    char option;
    cout << "how do you want to schedule processes FCFS or SJF?(enter f for FCFS or s for SJF)" << endl;
    cin >> option;
    switch(option){
     case 'f':
              cout << "Scheduling processes with FCFS...\n";
              scheduler.firstComeFirstServed(readyQueue);
              break;
    case 's':
              cout << "Scheduling processes with SJF...\n";
              scheduler.shortestJobFirst(readyQueue, totalCycleCount);
              break;
    }
      
}

bool readyQueueIsEmpty() const {
        return readyQueue.empty();
    }

    Process popFromReadyQueue() {
        if (!readyQueue.empty()) {
            Process process = readyQueue.front();
            readyQueue.pop();
            return process;
        }
        return Process();
    }

    void pushToWaitingQueue(const Process& process) {
        waitingQueue.push(process);
    }
     bool waitingQueueIsEmpty() const {
        return waitingQueue.empty();
    }

    Process popFromWaitingQueue() {
        if (!waitingQueue.empty()) {
            Process process = waitingQueue.front();
            waitingQueue.pop();
            return process;
        }
        return Process();
    }
};

#endif