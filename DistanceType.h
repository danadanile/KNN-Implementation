#ifndef DISTANCETYPE_H_
#define DISTANCETYPE_H_
#include <cstring>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/// @brief distance type class.
class DistanceType {
    /// @brief distance type by int.
    int distanceNum;

public:
    /// @brief constructor for distance.
    /// @param disType num symbolized the type.
    DistanceType(int disType);

    /// @brief constructor empty for distance.
    DistanceType();

    /// @brief check if the same len
    /// @param p vec one.
    /// @param q vec two.
    /// @return num of same.
    static int checkSameLenght(vector<double> p, vector<double> q);

    /// @brief calc the distance
    /// @param p vec one.
    /// @param q vec two.
    /// @return the distance.
    double calcDistanceType(vector<double> p, vector<double> q);

    /// @brief get input.
    /// @param vec the vector.
    /// @return value.
    int getInput(vector<double> &vec);

    /// @brief cala the diff.
    /// @param p num one.
    /// @param q num two.
    /// @return the diff
    double calcDiff(double p, double q);

    /// @brief calc minkowsky.
    /// @param p vector one.
    /// @param q vector two.
    /// @param k param
    /// @return distance.
    double disMinkowski(vector<double> p, vector<double> q, double k);

    /// @brief calc disEclidean.
    /// @param p vector one.
    /// @param q vector two.
    /// @return distance.
    double disEclidean(vector<double> p, vector<double> q);

    /// @brief calc disGeometry.
    /// @param p vector one.
    /// @param q vector two.
    /// @return distance.
    double disGeometry(vector<double> p, vector<double> q);

    /// @brief calc chebyshevDistance.
    /// @param vec1 one.
    /// @param vec2 two.
    /// @return distance.
    double chebyshevDistance(vector<double> vec1, vector<double> vec2);

    /// @brief calc disCanberra.
    /// @param p vector one.
    /// @param q vector two.
    /// @return distance.
    double disCanberra(vector<double> p, vector<double> q);
};
#endif