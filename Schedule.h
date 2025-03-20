#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include "Process.h"
#include "Kernel.h"

using namespace std;

class Schedule{
public:


void firstComeFirstServed(queue<Process>& readyQueue){
   
}

void shortestJobFirst(queue<Process>& readyQueue, int totalCycleCount){
vector<Process> processList;

if(totalCycleCount % 1000 == 0){
    Process newProcess;
    readyQueue.push(newProcess);
}

while (!readyQueue.empty()) {
    processList.push_back(readyQueue.front());
    readyQueue.pop();
}
sort(processList.begin(), processList.end(),
        [](const Process& a, const Process& b) {
            return a.getBurstCycle() < b.getBurstCycle();
        }
        );

for (const auto& process : processList) {
    readyQueue.push(process);
}

}

};

#endif