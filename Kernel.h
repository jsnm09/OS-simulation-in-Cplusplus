#ifndef KERNEL_H
#define KERNEL_H
#include <iostream>
#include <vector>
#include <queue>
#include "Process.h"
#include "Schedule.h"
#include "MemoryManager.h"
#include <unistd.h>
#include <string>

using namespace std;

class Kernel{
private:
vector<Process> processes;
queue<Process> readyQueue;
queue<Process> waitingQueue;
Schedule scheduler;
MemoryManager memoryManager;

public:
Kernel() : memoryManager(1024) {}

void start(){
cout << "Starting JamOS...\n";
sleep(5);
}
void loggin(){
    cout << "Logging in as guest\n";
sleep(5);
}

void addProcess(const Process& process){
    int address = memoryManager.allocate(process.getMemoryFootprint());
    if (address != -1) {
        Process newProcess = process;
        newProcess.setMemoryAddress(address);
        processes.push_back(newProcess);
        readyQueue.push(newProcess);
        cout << "Process added: " << newProcess.getProcessID() 
             << " with burst cycle: " << newProcess.getBurstCycle() 
             << " and memory address: " << newProcess.getMemoryAddress() << endl;
    } else {
        cout << "Failed to add process " << process.getProcessID() << " due to lack of memory." << endl;
    }
}

void printMemoryMap() const {
    memoryManager.printMemoryMap();
}

queue<Process>& getReadyQueue() {
    return readyQueue;
}

MemoryManager& getMemoryManager() {
    return memoryManager;
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