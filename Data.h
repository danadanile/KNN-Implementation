#ifndef DATA_H_
#define DATA_H_
#include <cstring>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include "VectorMap.h"
#include "DistanceType.h"
using namespace std;

class Data {
    /// @brief distance type by int.
    VectorMap vec;
    DistanceType dis;
    int k;

public:
    Data();
    Data(string fname, int disType, int k);
    DistanceType getDis();
    int getk();
    VectorMap getVectorMap();


};
#endif