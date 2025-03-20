#include <iostream>
#include "BIOS.h"
#include "Kernel.h"
#include "Schedule.h"
#include "Process.h"
using namespace std;


int main(){
Bios bios;
Kernel kernel;
int numberOfProcesses = 45;
Process CPU[1];
int totalCycleCount = 0;

bios.boot();

for(int i = 0; i < numberOfProcesses; i++){
    Process process;
    kernel.addProcess(process);

}

kernel.scheduleProcesses(totalCycleCount);

    while (totalCycleCount < 10000) {
        if (!kernel.readyQueueIsEmpty()) {
            CPU[0] = kernel.popFromReadyQueue();
            cout << "Processing Process ID: " << CPU[0].getProcessID() << endl;

            int cycleCount = 0;
            while (cycleCount < CPU[0].getBurstCycle() && totalCycleCount < 10000) {
                cycleCount++;
                totalCycleCount++;
                //cout << " Burst Cycle " << cycleCount << " (Total Cycles: " << totalCycleCount << ")" << endl;
            }

            cout << "Process ID: " << CPU[0].getProcessID() << " completed its CPU burst" << endl;
            kernel.pushToWaitingQueue(CPU[0]);
        }

        while (!kernel.waitingQueueIsEmpty()) {
            Process process = kernel.popFromWaitingQueue();
            kernel.addProcess(process);
        }
    }

while (!kernel.waitingQueueIsEmpty()){
    CPU[0]=kernel.popFromWaitingQueue();

    int cycleCount = 0;
    while(cycleCount < CPU[0].getBurstCycle()){
        cycleCount++;
        totalCycleCount++;
    }
    kernel.addProcess(CPU[0]);

}

while(!kernel.readyQueueIsEmpty()){
    Process process = kernel.popFromReadyQueue();
}

if (!kernel.readyQueueIsEmpty() || !kernel.waitingQueueIsEmpty()) {
        cout << "There are processes left to execute.\n";
    } else {
        cout << "No processes left to execute.\n";
    }

    return 0;
}

