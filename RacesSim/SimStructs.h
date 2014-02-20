#ifndef SIMSTRUCTS_H
#define SIMSTRUCTS_H

#include <string>
#include <vector>

using namespace std;

const int XSize = 5;
const int YSize = 5;

struct RacePositions {
    string  race_name;
    int     posX;
    int     posY;
};

typedef vector<RacePositions> raceMap;
typedef vector<string> nameList;

#endif