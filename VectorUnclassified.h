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

class VectorUnclassified {
   
   //unordered_multimap<vector<double>, string, VectorHasher> vecUnclassified;
   vector<vector<double>> vecUnclassified;
   //vector<string> VectorResult;

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

    int getOneVecLength();

    void deleteTest();

    vector<vector<double>> getVecUnclassified();

    };
#endif