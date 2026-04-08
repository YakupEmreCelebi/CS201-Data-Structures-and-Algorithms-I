// Name: Yakup Emre Çelebi, Section : 2, ID: 22302267, Department: Computer Science

#ifndef TIMEBRANCH_H

#define TIMEBRANCH_H

#include <string>
#include <iostream>

#include "StringStack.h"

using namespace std;

class TimeBranch
{
private:
    int branchId;
    string currentLocation;

    StringStack *pastStack;
    StringStack *futureStack;

    StringStack *stoneStack;

public:
    TimeBranch(int id, string startLoc, int pastCap, int futureCap);

    ~TimeBranch();

    void travelTo(string newLocation);
    void fastForward(int k);

    void rewind(int k);

    void placeTimeStone();
    void activateTimeStone();

    void printBranchState() const;
    int getId() const;
    string getCurrentLocation() const;

    StringStack *getPastStack() const;

    StringStack *getFutureStack() const;
    StringStack *getStoneStack() const;
    int getPastCapacity() const;

    int getFutureCapacity() const;
};
#endif