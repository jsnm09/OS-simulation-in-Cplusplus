# OS Simulation in C++

This project is a command-line-based simulation of a basic operating system, written in C++. It provides a hands-on demonstration of core OS concepts, including process management, CPU scheduling, and memory management.

## Core Features

### 1. Process Management
- **Dynamic Process Creation:** Users can create new processes on-the-fly. Each process is assigned a unique Process ID (PID), a random CPU burst cycle, and a random memory footprint.

### 2. Memory Management
- **First-Fit Allocation:** The system uses a Memory Manager with a fixed-size memory block (1024 bytes). It employs a First-Fit algorithm to find the first available block that is large enough for a new process.
- **Allocation & Deallocation:** Memory is allocated to processes upon creation and deallocated when they complete execution.
- **Memory Map Visualization:** Users can view the current state of the memory map, showing which blocks are allocated and which are free.

### 3. CPU Scheduling
- **Multiple Scheduling Algorithms:** The simulation implements three fundamental CPU scheduling algorithms:
    - **First-Come, First-Served (FCFS):** Processes are executed in the order they enter the ready queue.
    - **Shortest Job First (SJF):** A non-preemptive scheduler that executes the process with the smallest CPU burst cycle first.
    - **Round Robin:** A preemptive scheduler that gives each process a fixed time slice (quantum) of CPU time.
- **Interactive Scheduling:** Users can choose which scheduling algorithm to run on the current set of processes in the ready queue.

## How to Compile and Run

To compile and run the project, you need a C++ compiler like `g++`.

1. **Navigate to the project directory:**
   ```sh
   cd path/to/OS-simulation-in-Cplusplus
   ```

2. **Compile the source files:**
   ```sh
   g++ main.cpp -o JamOS.exe
   ```

3. **Run the executable:**
   ```sh
   ./JamOS.exe
   ```

## Interactive Shell
Once running, the program presents an interactive menu:

```
--- JamOS Main Menu ---
1. Create new processes
2. Schedule processes in Ready Queue
3. View Memory Map
4. Shutdown
Select an option:
```

- **Create new processes:** Prompts for the number of processes to create and adds them to the ready queue.
- **Schedule processes:** Asks which scheduling algorithm to use and executes the processes from the ready queue accordingly.
- **View Memory Map:** Displays the current status of all memory blocks.
- **Shutdown:** Exits the simulation.