#ifndef DISTANCETYPE_H_
#define DISTANCETYPE_H_
#include <cstring>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class DistanceType {
    /// @brief distance type by int.
    int distanceNum;

public:
    DistanceType(int disType);
    DistanceType();
    static int checkSameLenght(vector<double> p, vector<double> q);
    double calcDistanceType(vector<double> p, vector<double> q);
    int getInput(vector<double> &vec);
    double calcDiff(double p, double q);
    double disMinkowski(vector<double> p, vector<double> q, double k);
    double disEclidean(vector<double> p, vector<double> q);
    double disGeometry(vector<double> p, vector<double> q);
    double chebyshevDistance(vector<double> vec1, vector<double> vec2);
    double disCanberra(vector<double> p, vector<double> q);
};
#endif