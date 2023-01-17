#ifndef VECTORMAP_H_
#define VECTORMAP_H_
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

class VectorMap {
    /// @brief map of the file cataloged by vector and string name.
    multimap<vector<double>, string> mapi;
public:
    VectorMap(string fname);
    VectorMap();
    string knnFunc(vector<double> vecGet, int disNum, int k);
    int GetVectorLength();
    int getSizeMap();
    multimap<vector<double>, string> getMapi();
    
};
#endif