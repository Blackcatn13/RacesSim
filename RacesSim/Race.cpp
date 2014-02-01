#include "Race.h"
#include <iostream>

Race::Race(void)
{
    m_Population = 0;
    m_PopulationGrowthRate = 0;
    m_PopulationCurrentGrowthRate = 0;
    m_ExpandProbability = 0;
    m_FightProbability = 0;
    m_AttackBackProbability = 0;
    m_PeaceProbability = 0;
    m_CrossoverProbability = 0;
    m_Fighting = false; 
    m_PopulationGettingDamage = false;
    m_TimeInPeace = 0;
    m_PopulationPeaceGrowth = 0;
    m_PopulationPeaceGrowthRate = 0;
    m_TimeInWar = 0;
    m_PopulationWarGrowth = 0;
    m_PopulationWarGrowthRate = 0;
    m_DeadRace = false;
    m_MilitaryPopulation = 0;
    m_MilitaryRate = 0;
    m_MilitaryTrait = 0;
    m_NaturistTrait = 0;
    m_ScienceTrait = 0;
    m_TotalTraitsPoints = 0;
}


Race::~Race(void)
{
}

Race::Race(long int pop, float popRate, float expRate, float figRate, float attRate, float peaRate, float crossRate, float milRate, bool fight)
{
    m_Population = pop;
    m_MilitaryPopulation = 0;
    m_MilitaryRate = milRate;
    m_PopulationGrowthRate = popRate;
    m_PopulationCurrentGrowthRate = popRate;
    m_ExpandProbability = expRate;
    m_FightProbability = figRate;
    m_AttackBackProbability = attRate;
    m_PeaceProbability = peaRate;
    m_CrossoverProbability = crossRate;
    m_Fighting = fight;
    m_PopulationGettingDamage = false;
    m_TimeInPeace = 0;
    m_PopulationPeaceGrowth = 0;
    m_PopulationPeaceGrowthRate = 0;
    m_TimeInWar = 0;
    m_PopulationWarGrowth = 0;
    m_PopulationWarGrowthRate = 0;
    m_DeadRace = false;
    m_MilitaryTrait = 0;
    m_NaturistTrait = 0;
    m_ScienceTrait = 0;
    m_TotalTraitsPoints = 0;
}

void Race::addMilitaryTrait(int traits)
{
    float MilitaryTraits = m_MilitaryTrait * m_TotalTraitsPoints;
    float ScienceTraits = m_ScienceTrait * m_TotalTraitsPoints;
    float NaturistTraits = m_NaturistTrait * m_TotalTraitsPoints;
    m_TotalTraitsPoints = MilitaryTraits + ScienceTraits + NaturistTraits + traits;
    m_MilitaryTrait = (MilitaryTraits + traits) / m_TotalTraitsPoints;
    m_ScienceTrait = ScienceTraits / m_TotalTraitsPoints;
    m_NaturistTrait = NaturistTraits / m_TotalTraitsPoints;
}

void Race::addScienceTrait(int traits)
{
    float MilitaryTraits = m_MilitaryTrait * m_TotalTraitsPoints;
    float ScienceTraits = m_ScienceTrait * m_TotalTraitsPoints;
    float NaturistTraits = m_NaturistTrait * m_TotalTraitsPoints;
    m_TotalTraitsPoints = MilitaryTraits + ScienceTraits + NaturistTraits + traits;
    m_MilitaryTrait = MilitaryTraits / m_TotalTraitsPoints;
    m_ScienceTrait = (ScienceTraits + traits) / m_TotalTraitsPoints;
    m_NaturistTrait = NaturistTraits / m_TotalTraitsPoints;
}

void Race::addNaturistTrait(int traits)
{
    float MilitaryTraits = m_MilitaryTrait * m_TotalTraitsPoints;
    float ScienceTraits = m_ScienceTrait * m_TotalTraitsPoints;
    float NaturistTraits = m_NaturistTrait * m_TotalTraitsPoints;
    m_TotalTraitsPoints = MilitaryTraits + ScienceTraits + NaturistTraits + traits;
    m_MilitaryTrait = MilitaryTraits / m_TotalTraitsPoints;
    m_ScienceTrait = ScienceTraits / m_TotalTraitsPoints;
    m_NaturistTrait = (NaturistTraits + traits) / m_TotalTraitsPoints;
}

void Race::Update(double tick)
{

}

void Race::UpdateRelationShips(double tick)
{

}

void Race::UpdatePopulation(double tick)
{
    // If the race is not dead
    if(!m_DeadRace)
    {
        // If the races is not currently fighting
        if(!m_Fighting)
        {
            m_TimeInWar = 0;            
            if(m_TimeInPeace == 0)
                m_PopulationCurrentGrowthRate = m_PopulationGrowthRate;
            // If it has been enough time in peace increase the growth rate
            if(m_TimeInPeace >= m_PopulationPeaceGrowth)
            {
                m_PopulationCurrentGrowthRate += m_PopulationPeaceGrowthRate;
                m_TimeInPeace = 0;
            }
            m_Population += tick * 1000 * m_PopulationCurrentGrowthRate;
            m_MilitaryPopulation = m_Population * (m_MilitaryRate + 0.25 * m_MilitaryTrait);
            m_TimeInPeace += tick;
        }
        else
        // If we are in war at the moment
        {
            m_TimeInPeace = 0;
            if(m_TimeInWar == 0 && !m_PopulationGettingDamage)
                m_PopulationCurrentGrowthRate = 0;
            if(m_TimeInWar >= m_PopulationWarGrowth)
            {
                // If it has been enough time in war and the population is having damage change the growth rate
                if(m_PopulationGettingDamage)
                    m_PopulationCurrentGrowthRate += m_PopulationWarGrowthRate;
                else
                    // If the population is not having damage
                    m_PopulationCurrentGrowthRate = 0;
                m_TimeInWar = 0;
            }
            int death = tick * 1000 * m_PopulationCurrentGrowthRate;
            if(m_MilitaryPopulation > 0)
            {
                int diff = m_MilitaryPopulation + death;
                if(diff < 0)
                {
                    m_MilitaryPopulation = 0;
                    m_Population += diff;
                }
                else
                {
                    m_MilitaryPopulation += death;
                }
            }
            else
            {
                m_Population += death;
            }
            m_TimeInWar += tick;
        }
        if(m_Population <= 0) 
            m_DeadRace = true;
    }

    // ------
    // Debug
    // ------
    std::cout << "Growth Rate: " << m_PopulationCurrentGrowthRate << std::endl;
    std::cout << "Population:          " << m_Population << std::endl;
    std::cout << "Military population: " << m_MilitaryPopulation << std::endl;
    std::cout << std::endl;
    //int i;
    //std::cin >> i;
}
