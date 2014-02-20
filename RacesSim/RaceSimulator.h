#ifndef RaceSimulator_H
#define RaceSimulator_H

#include "Structs.h"

class RaceSimulator
{
private:
    static RaceSimulator *m_RaceSimulator;
    RaceSimulator();

    raceMap     m_RaceMap;

public:
    ~RaceSimulator();

    static RaceSimulator* getInstance();

    void Simulate();
    nameList getNeighbors(string race, int sight);
    bool NewCity(string race);
    bool NewCity(string race1, string race2);

};

#endif

