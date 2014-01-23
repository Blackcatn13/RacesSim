#ifndef Race_H
#define Race_H

class Race
{
public:
    Race(void);
    ~Race(void);

    void Update(float tick);

protected:
    long int    m_Population;
    float       m_PopulationGrowthRate;
    float       m_ExpandProbability;
    float       m_FigthProbability;
    float       m_AttackBackProbability;
    float       m_PeaceProbability;
    float       m_CrossoverProbability;
};

#endif

