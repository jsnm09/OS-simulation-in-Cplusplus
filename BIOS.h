#ifndef BIOS_H
#define BIOS_H
#include <iostream>
#include "Kernel.h"
using namespace std;

class Bios :public Kernel{
public:

void boot(){
cout << "Bios is starting up\n";
start();
loggin();
}

};

#endif