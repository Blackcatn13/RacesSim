#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
using namespace std;

struct RaceRelations {
    string  Name;
    float   Relation;
    bool    Fighting;
};

enum CityPolicy {DIVIDE = 0, QUARTER, RATE};


#endif