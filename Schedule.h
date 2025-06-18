#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include "Process.h"
#include "Kernel.h"
#include "MemoryManager.h"

using namespace std;

class Schedule{
public:


void firstComeFirstServed(queue<Process>& readyQueue, MemoryManager& memoryManager){
    if (readyQueue.empty()) {
        cout << "Ready queue is empty. No processes to schedule." << endl;
        return;
    }

    Process currentProcess = readyQueue.front();
    readyQueue.pop();

    cout << "Executing process " << currentProcess.getProcessID() 
         << " with burst cycle " << currentProcess.getBurstCycle() << endl;
    
    memoryManager.deallocate(currentProcess.getMemoryAddress());
}

void shortestJobFirst(queue<Process>& readyQueue, MemoryManager& memoryManager){
    if (readyQueue.empty()) {
        cout << "Ready queue is empty. No processes to schedule." << endl;
        return;
    }
    
    vector<Process> processList;
    while (!readyQueue.empty()) {
        processList.push_back(readyQueue.front());
        readyQueue.pop();
    }
    
    sort(processList.begin(), processList.end(),
            [](const Process& a, const Process& b) {
                return a.getBurstCycle() < b.getBurstCycle();
            }
            );

    Process shortestProcess = processList.front();
    processList.erase(processList.begin());

    cout << "Executing process " << shortestProcess.getProcessID() 
         << " with burst cycle " << shortestProcess.getBurstCycle() << endl;

    memoryManager.deallocate(shortestProcess.getMemoryAddress());

    for (const auto& process : processList) {
        readyQueue.push(process);
    }
}

void roundRobin(queue<Process>& readyQueue, int quantum, MemoryManager& memoryManager) {
    if (readyQueue.empty()) {
        return;
    }

    Process currentProcess = readyQueue.front();
    readyQueue.pop();

    int burstTime = currentProcess.getBurstCycle();

    if (burstTime > quantum) {
        currentProcess.setBurstCycle(burstTime - quantum);
        readyQueue.push(currentProcess);
        cout << "Process " << currentProcess.getProcessID() << " ran for " << quantum 
             << " cycles. Remaining burst: " << currentProcess.getBurstCycle() << endl;
    } else {
        cout << "Process " << currentProcess.getProcessID() << " finished execution." << endl;
        memoryManager.deallocate(currentProcess.getMemoryAddress());
    }
}

};

#endif