#ifndef Race_H
#define Race_H

class Race
{
public:
    Race(void);
    ~Race(void);
    Race(long int, float, float, float, float, float, float, bool);

    void Update(double tick);

    void setPopulationPeaceGrowth(double time) {m_PopulationPeaceGrowth = time;}
    void setPopulationPeaceGrowthRate(float rate) {m_PopulationPeaceGrowthRate = rate;}
    void setPopulationWarGrowth(double time) {m_PopulationWarGrowth = time;}
    void setPopulationWarGrowthRate(float rate) {m_PopulationWarGrowthRate = rate;}
    void setFighting(bool fight) {m_Fighting = fight;}
    void setPopulationGettingDamage(bool damage) {m_PopulationGettingDamage = damage;}

protected:
    long int    m_Population;
    float       m_PopulationGrowthRate;
    float       m_PopulationCurrentGrowthRate;
    float       m_ExpandProbability;
    float       m_FigthProbability;
    float       m_AttackBackProbability;
    float       m_PeaceProbability;
    float       m_CrossoverProbability;
    bool        m_Fighting; 
    //bool        m_Peace;
    bool        m_PopulationGettingDamage;
    double      m_TimeInPeace;
    double      m_PopulationPeaceGrowth;
    float       m_PopulationPeaceGrowthRate;
    double      m_TimeInWar;
    double      m_PopulationWarGrowth;
    float       m_PopulationWarGrowthRate;
    bool        m_DeadRace;
};

#endif

