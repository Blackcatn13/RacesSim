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
}


Race::~Race(void)
{
}

Race::Race(long int pop, float popRate, float expRate, float figRate, float attRate, float peaRate, float crossRate, bool fight)
{
    m_Population = pop;
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
}

void Race::Update(double tick)
{
    std::cout << "Tick value: " << tick << std::endl;
    if(!m_DeadRace)
    {
        if(!m_Fighting)
        {
            m_TimeInWar = 0;            
            if(m_TimeInPeace == 0)
                m_PopulationCurrentGrowthRate = m_PopulationGrowthRate;
            if(m_TimeInPeace >= m_PopulationPeaceGrowth)
            {
                m_PopulationCurrentGrowthRate += m_PopulationPeaceGrowthRate;
                m_TimeInPeace = 0;
            }
            m_Population += tick * 1000 * m_PopulationCurrentGrowthRate;
            m_TimeInPeace += tick;
        }
        else
        {
            m_TimeInPeace = 0;
            if(m_TimeInWar == 0 && !m_PopulationGettingDamage)
                m_PopulationCurrentGrowthRate = 0;
            if(m_TimeInWar >= m_PopulationWarGrowth)
            {
                if(m_PopulationGettingDamage)
                    m_PopulationCurrentGrowthRate += m_PopulationWarGrowthRate;
                else
                    m_PopulationCurrentGrowthRate = 0;
                m_TimeInWar = 0;
            }
            m_Population += tick * 1000 * m_PopulationCurrentGrowthRate;
            m_TimeInWar += tick;
        }
        if(m_Population <= 0) 
            m_DeadRace = true;
    }
    std::cout << "Growth Rate: " << m_PopulationCurrentGrowthRate << std::endl;
    std::cout << "New population :" << m_Population << std::endl;
    std::cout << std::endl;
    //int i;
    //std::cin >> i;
}
