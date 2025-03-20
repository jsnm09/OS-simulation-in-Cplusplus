#ifndef PROCESS_H
#define PROCESS_H
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Process{
private:
int processID;
int burstCycle;
int IoCycle;
public:

Process(){
    static bool isSeeded = false;

    if(!isSeeded){
        srand(time(NULL));
        isSeeded = true;
    }
    processID = 10000 + rand() % 90000;
    IoCycle = rand() % 5+1;
    burstCycle = rand() % 10+3;
}

int getProcessID() const {
    return processID;
}
int getBurstCycle() const{
    return burstCycle;
}
int getIOCycle() const{
    return IoCycle;
}
};

#endif