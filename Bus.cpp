#include "Bus.h"
#include "Bus.h"

// Constructor
Bus::Bus(vector<string> stations, Time_ start, Time_ end, int duration, int relax)
    : stations(stations), start(start), end(end), duration(duration), relax(relax) {}

// Methods to add and delete stations
void Bus::addStation(int number, string name) {
    if (number >= 0 && number <= stations.size()) {
        stations.insert(stations.begin() + number, name);
    }
}

void Bus::delStation(int number) {
    if (number >= 0 && number < stations.size()) {
        stations.erase(stations.begin() + number);
    }
}

// Getters
Time_ Bus::getStart() const {
    return start;
}

Time_ Bus::getEnd() const {
    return end;
}

int Bus::getDuration() const {
    return duration;
}

int Bus::getRelax() const {
    return relax;
}

// Setters
void Bus::setStart(Time_ start) {
    this->start = start;
}

void Bus::setEnd(Time_ end) {
    this->end = end;
}

void Bus::setDuration(int duration) {
    this->duration = duration;
}

void Bus::setRelax(int relax) {
    this->relax = relax;
}

// Show bus info
void Bus::showInfo() const {
    cout << "Bus route info:" << endl;
    cout << "Stations: ";
    for (const auto& station : stations) {
        cout << station << " ";
    }
    cout << endl;
    cout << "Start time: ";
    start.showTime();
    cout << endl;
    cout << "End time: ";
    end.showTime();
    cout << endl;
    cout << "Duration: " << duration << " minutes" << endl;
    cout << "Relax time: " << relax << " minutes" << endl;
}

// Print schedule
void Bus::printSchedule() const {
    cout << "Daily schedule:" << endl;
    Time_ current = start;
    while (current <= end) {
        current.showTime();
        cout << " ";
        current += duration;
        current.showTime();
        cout << endl;
        current += relax;
    }
}
