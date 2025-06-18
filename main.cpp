#include <iostream>
#include "BIOS.h"
#include "Kernel.h"
#include "Schedule.h"
#include "Process.h"

using namespace std;

void displayMenu() {
    cout << "\n--- JamOS Main Menu ---\n"
         << "1. Create new processes\n"
         << "2. Schedule processes in Ready Queue\n"
         << "3. View Memory Map\n"
         << "4. Shutdown\n"
         << "Select an option: ";
}

void scheduleProcesses(Kernel& kernel, Schedule& scheduler) {
    if (kernel.readyQueueIsEmpty()) {
        cout << "Ready Queue is empty. Nothing to schedule." << endl;
        return;
    }

    char option;
    cout << "How do you want to schedule? (f for FCFS, s for SJF, r for Round Robin): ";
    cin >> option;

    int quantum = 0;
    if (option == 'r') {
        cout << "Enter time quantum for Round Robin: ";
        cin >> quantum;
    }

    while (!kernel.readyQueueIsEmpty()) {
        cout << "----------------------------------------\n";
        switch (option) {
            case 'f':
                scheduler.firstComeFirstServed(kernel.getReadyQueue(), kernel.getMemoryManager());
                break;
            case 's':
                scheduler.shortestJobFirst(kernel.getReadyQueue(), kernel.getMemoryManager());
                break;
            case 'r':
                scheduler.roundRobin(kernel.getReadyQueue(), quantum, kernel.getMemoryManager());
                break;
            default:
                cout << "Invalid scheduling option." << endl;
                return; 
        }
        kernel.printMemoryMap();
    }
    cout << "----------------------------------------\n";
    cout << "All processes in the ready queue have been executed." << endl;
}

int main() {
    Bios bios;
    Kernel kernel;
    Schedule scheduler;
    bool powerOn = true;

    bios.boot();

    while (powerOn) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int num;
                cout << "How many processes to create? ";
                cin >> num;
                for (int i = 0; i < num; ++i) {
                    Process p;
                    kernel.addProcess(p);
                }
                break;
            }
            case 2:
                scheduleProcesses(kernel, scheduler);
                break;
            case 3:
                kernel.printMemoryMap();
                break;
            case 4:
                powerOn = false;
                cout << "Shutting down JamOS..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }

    return 0;
}

