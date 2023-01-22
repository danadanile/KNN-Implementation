#ifndef VECTORMAP_H_
#define VECTORMAP_H_
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

/// @brief class with map member that same the test vectors (Unclassified vector).
class VectorMap {
    multimap<vector<double>, string> mapi;

public:

    /// @brief constructor
    /// @param stream file content.
    VectorMap(stringstream &stream);

    /// @brief constructor.
    VectorMap();

    /// @brief calculates the K-nearest-neighbors by vector.
    /// @param vecGet the vector.
    /// @param disNum distance type.
    /// @param k nearest-neighbors.
    /// @return the name of the nearest-neighbors.
    string knnFunc(vector<double> vecGet, int disNum, int k);

    /// @brief return the length of the vector in the map
    /// @return the first vector length, which symbolized the rest of vectors.
    int GetVectorLength();

    /// @brief get the number of rows in the map.
    /// @return the map size.
    int getSizeMap();


    multimap<vector<double>, string> getMapi();
    
};
#endif