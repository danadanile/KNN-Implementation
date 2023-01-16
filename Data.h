#ifndef DATA_H_
#define DATA_H_
#include <cstring>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include "VectorMap.h"
#include "DistanceType.h"
#include "VectorUnclassified.h"
using namespace std;

class Data {
    /// @brief distance type by int.
    VectorMap train;
    string disName;
    int k;
    DistanceType disType;
    VectorUnclassified test;

public:
    Data();
    Data(string fname, string disNum, int k, DistanceType disType);
    string getDisName();
    int getk();
    void setK(int newK);
    void setDisName(string newDisName);
    void setDisType(DistanceType newDisType);
    VectorMap getVectorMap();
    VectorUnclassified getTest();


};
#endif