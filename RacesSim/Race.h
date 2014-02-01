#ifndef Race_H
#define Race_H

#include <string>
#include <vector>
#include "Structs.h"

using namespace std;

typedef vector<RaceRelations> relation; 

class Race
{
public:
    Race(void);
    ~Race(void);
    Race(long int, float, float, float, float, float, float, float, bool);

    void Update(double tick);
    void UpdatePopulation(double tick);
    void UpdateRelationShips(double tick);

    void setPopulationPeaceGrowth(double time) {m_PopulationPeaceGrowth = time;}
    void setPopulationPeaceGrowthRate(float rate) {m_PopulationPeaceGrowthRate = rate;}
    void setPopulationWarGrowth(double time) {m_PopulationWarGrowth = time;}
    void setPopulationWarGrowthRate(float rate) {m_PopulationWarGrowthRate = rate;}
    void setFighting(bool fight) {m_Fighting = fight;}
    void setPopulationGettingDamage(bool damage) {m_PopulationGettingDamage = damage;}
    void addMilitaryTrait(int traits);
    void addScienceTrait(int traits);
    void addNaturistTrait(int traits);

protected:
    // ------------------
    // Race Parameters
    // ------------------

    // Name of the race, to identify it.
    string      m_RaceName;
    // Vector with the relationship with other races.
    relation    m_RelationShip;

    // ------------------
    // Race Values
    // ------------------

    // Population value of the race.
    long int    m_Population;
    // The population that's military in the race.
    long int    m_MilitaryPopulation;

    // ------------------
    // Race Nature
    // ------------------

    // Rate of growing of the population.
    float       m_PopulationGrowthRate;
    // Probability of expanding over the world if sufficient population reached.
    float       m_ExpandProbability;
    // Probability of picking a fight if other races is near.
    float       m_FightProbability;
    // Probability of fighting back if under attack.
    float       m_AttackBackProbability;
    // Probability of making peace if under or ongoing attack.
    float       m_PeaceProbability;
    // Probability of crossover the race with other neighbor races.
    float       m_CrossoverProbability;
    // Rate of growing when not in war.
    float       m_PopulationPeaceGrowthRate;
    // Rate of growing when in war and under attack.
    float       m_PopulationWarGrowthRate;
    // Percentage of military traits of the race.
    float       m_MilitaryTrait;
    // Percentage of science traits of the race.
    float       m_ScienceTrait;
    // Percentage of naturist traits of the race.
    float       m_NaturistTrait;
    // Percentage of population converted to military
    float       m_MilitaryRate;

    // ------------------
    // Auxiliary vars
    // ------------------

    float       m_PopulationCurrentGrowthRate;
    float       m_TotalTraitsPoints;

    bool        m_DeadRace;
    bool        m_Fighting; 
    bool        m_PopulationGettingDamage;

    double      m_TimeInPeace;
    double      m_PopulationPeaceGrowth;
    double      m_TimeInWar;
    double      m_PopulationWarGrowth;
};

#endif

