
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Time_.h"

using namespace std;

class Bus {
private:
    vector<string> stations;
    Time_ start;
    Time_ end;
    int duration; // Duration in minutes
    int relax; // Relax time in minutes

public:
    Bus(vector<string> stations, Time_ start, Time_ end, int duration, int relax);

    void addStation(int number, string name);
    void delStation(int number);

    Time_ getStart() const;
    Time_ getEnd() const;
    int getDuration() const;
    int getRelax() const;

    void setStart(Time_ start);
    void setEnd(Time_ end);
    void setDuration(int duration);
    void setRelax(int relax);

    void showInfo() const;
    void printSchedule() const;
};
