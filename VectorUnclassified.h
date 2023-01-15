#ifndef VECTORUNCLASSIFIED_H_
#define VECTORUNCLASSIFIED_H_
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

class VectorUnclassified {
    /// @brief map of the file cataloged by vector and string name.
    multimap<vector<double>, string> vecUnclassified;
public:
    VectorUnclassified(string fname);
    VectorUnclassified();
    int GetVectorLength();
    int getSizeMap();
    bool updateString(vector<double>, string nameClassify);
};
#endif