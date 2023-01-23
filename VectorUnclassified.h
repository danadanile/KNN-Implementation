#ifndef VECTORUNCLASSIFIED_H_
#define VECTORUNCLASSIFIED_H_
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include "VectorMap.h"

using namespace std;

/// @brief Vectors for Unclassified data.
class VectorUnclassified {
   
   vector<vector<double>> vecUnclassified;

public:
    /// @brief constructor.
    VectorUnclassified();

    /// @brief The class create map by file name. the first column in the map
    /// is the vector, the second is the name "".
    /// @param fname as a file name.
    VectorUnclassified(stringstream &stream);


    /// @brief return the length of the vector in the map
    /// @return the first vector length, which symbolized the rest of vectors.
    int getTestLength();

    /// @brief get the length of the vectors
    /// @return  th len
    int getOneVecLength();

    /// @brief delete the obj.
    void deleteTest();

    /// @brief get vector of unclassified.
    /// @return  the vector/
    vector<vector<double>> getVecUnclassified();

    };
#endif