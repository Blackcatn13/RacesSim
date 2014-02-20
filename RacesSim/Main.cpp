#include <iostream>
#include <time.h>
#include "Race.h"

int main ()
{
    //std::vector<RaceRelations> v1(10, RaceRelations());

    Race r = Race(100, 0.5, 0, 0, 0, 0, 0, .15, false);
    r.setPopulationPeaceGrowth(1);
    r.setPopulationPeaceGrowthRate(0.1);
    r.setPopulationWarGrowth(0.8);
    r.setPopulationWarGrowthRate(-0.2);
    int i = 1;
    clock_t init_Time = clock();
    clock_t next_Time;
    while (i < 800)
    {
        if(i == 100)
            r.setFighting(true);
        if(i == 130)
            r.setPopulationGettingDamage(true);
        if(i == 200)
        {
            r.setPopulationGettingDamage(false);
            r.setFighting(false);
            r.addMilitaryTrait(100);
        }
        if(i == 600)
            r.setFighting(true);
        if(i == 620)
            r.setPopulationGettingDamage(true);

        next_Time = clock();
        double tick = ((double) next_Time - init_Time)/CLOCKS_PER_SEC;
        if(tick > 0.1)
        {
            std::cout << "Iteration:   " << i << std::endl;
            r.UpdatePopulation(tick);
            init_Time = next_Time;
            i++;
            //std::cin.get();
        }
    }
    std::cin >> i;
}