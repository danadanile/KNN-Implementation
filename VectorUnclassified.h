#ifndef VECTORUNCLASSIFIED_H_
#define VECTORUNCLASSIFIED_H_
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include "VectorMap.h"

using namespace std;

class VectorUnclassified {
   
    multimap<vector<double>, string> vecUnclassified;
public:
    /// @brief constructor.
    VectorUnclassified();

    /// @brief The class create map by file name. the first column in the map
    /// is the vector, the second is the name "".
    /// @param fname as a file name.
    VectorUnclassified(stringstream &fname);

    /// @brief get the number of rows in the map.
    /// @return the size map.
    int getSizeMap();

    /// @brief return the length of the vector in the map
    /// @return the first vector length, which symbolized the rest of vectors.
    int GetVectorLength();


    void classify(VectorMap* train, int k, int disType);


    multimap<vector<double>, string> getVecUnclassified();

    };
#endif