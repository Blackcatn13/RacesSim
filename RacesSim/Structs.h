#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include <vector>

using namespace std;

const int XSize = 5;
const int YSize = 5;

struct RaceRelations {
    string  Name;
    float   Relation;
    bool    Fighting;
};

struct RacePositions {
    string  race_name;
    int     posX;
    int     posY;
};

enum CityPolicy {DIVIDE = 0, QUARTER, RATE};
typedef vector<RaceRelations> relation;
typedef vector<string> nameList;
typedef vector<RacePositions> raceMap;

#endif