#pragma once
#include <iostream>
#include <string>
using namespace std;
class Computer
{
 private:
    string processor;
    int OPvolume;
    int HDvolume;
 public:
    Computer();
    Computer(string, int, int);
    Computer(const Computer&);
    ~Computer();
    string getprocessor();
    void setprocessor(string);
    int getOPvolume();
    void setOPvolume(int);
    int getHDvolume();
    void setHDvolume(int);
    void show();
};