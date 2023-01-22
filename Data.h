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

class Data
{
    /// @brief class data save all data that the client need.
    string disName;
    int k;
    int disType;
    VectorUnclassified *test;
    VectorMap *train;
    bool trainIsInit;
    bool testIsInit;
    bool isClassified;

public:
    /// @brief constructor.
    Data();

    /// @brief get distance name.
    /// @return  distance name
    string getDisName();

    /// @brief get k
    /// @return k
    int getK();

    /// @brief get pointer to test object.
    /// @return pointer to test object.
    VectorUnclassified *getTest();

    /// @brief get pointer to train object.
    /// @return pointer to train object.
    VectorMap *getTrain();

    /// @brief get bool that indicate if test obj is init.
    /// @return true if init
    bool getTestIsInit();

    /// @brief get bool that indicate if train obj is init.
    /// @return true if init
    bool getTrainIsInit();

    /// @brief get bool that indicates if data was classified.
    /// @return true if classified
    bool getIsClassified();

    /// @brief set k value
    /// @param newK k
    void setK(int newK);

    /// @brief distance name
    /// @param newDisName
    void setDisName(string newDisName);

    /// @brief distance nymber(enum convert)
    /// @param newDisType
    void setDisType(int newDisType);

    /// @brief set train indicator
    /// @param b
    void setTrainIsInit(bool b);

    /// @brief set test indicator
    /// @param b
    void setTestIsInit(bool b);

    /// @brief set test object
    /// @param fname
    void setTest(stringstream &fname);

    /// @brief set train object
    /// @param fname
    void setTrain(stringstream &fname);

    /// @brief call classification of data func on vectorUnclassified object
    void classifyData();

    /// @brief set classify indicator
    /// @param b
    void SetIsClassified(bool b);
};
#endif