#ifndef RACESTRUCTS_H
#define RACESTRUCTS_H

#include <string>
#include <vector>

using namespace std;

struct RaceRelations {
    string  Name;
    float   Relation;
    bool    Fighting;
};

enum CityPolicy {DIVIDE = 0, QUARTER, RATE};
typedef vector<RaceRelations> relation;

#endif