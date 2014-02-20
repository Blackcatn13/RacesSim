#include "RaceSimulator.h"
#include "Race.h"

RaceSimulator* RaceSimulator::m_RaceSimulator = 0;

RaceSimulator::~RaceSimulator()
{
}

RaceSimulator::RaceSimulator()
{

}

RaceSimulator* RaceSimulator::getInstance()
{
    if(m_RaceSimulator == 0)
        m_RaceSimulator = new RaceSimulator();
    return m_RaceSimulator;
}

void RaceSimulator::Simulate()
{

}

nameList RaceSimulator::getNeighbors(string name, int sight)
{
    return nameList();
}

bool RaceSimulator::NewCity(string race)
{
    return true;
}

bool RaceSimulator::NewCity(string race1, string race2)
{
    return true;
}
