#include <iostream>
#include "Bus.h"
#include "Time_.h"

int main() {
 
    Bus b1({ "Saltivka", "Istorychnyi Musei", "Pivdennyi Voksal" }, Time_(6, 0), Time_(21, 0), 30, 10);


    b1.showInfo();

   
    b1.printSchedule();

    return 0;
}
