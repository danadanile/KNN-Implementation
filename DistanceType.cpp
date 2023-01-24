#include <vector>
#include <cmath>
#include "DistanceType.h"
#include "CheckFuncs.h"
#define P 2
#define P_GEOMETRY 1
#define P_ECLIDEAN 2
using namespace std; 

/// @brief Class which calculates the distance by her type.
/// @param disType by int (which simbolaized distance name by enum).
DistanceType::DistanceType(int disType) {
    distanceNum=disType;
}

DistanceType::DistanceType() {
    distanceNum=0;
}


/// @brief calculates the distance by the type with switch case.
/// @param p vector one.
/// @param q vector two.
/// @return the distance by the type
double DistanceType::calcDistanceType(vector<double> p, vector<double> q) {
 
    switch (distanceNum)
    {
    case 1:
        return disEclidean(p,q);
        break;

    case 2:
        return disGeometry(p,q);
        break;
    
    case 3:
        return chebyshevDistance(p,q);
        break;

    case 4:
        return disCanberra(p,q);
        break;

    case 5:
        return disMinkowski(p,q,P);
        break;

    default:
        return 0;
        break;
    }
}

/// @brief Calculates diffrent and the abs.
/// @param p number 1.
/// @param q number 2.
/// @return the calculate result.
double DistanceType::calcDiff(double p, double q) {
    return std::abs(p-q);
}


/// @brief Calculates Minkowski distance.
/// @param p vector one.
/// @param q vector two.
/// @param k parameter.
/// @return the calculate result.
double DistanceType::disMinkowski(vector<double> p, vector<double> q, double k) {
    if (!CheckFuncs::checkSameLenght(p,q)){
        return 0;
    }
    int const vectorsSize = p.size();
    double sum = 0;
    if(vectorsSize == q.size())
    {
        for(int i = 0; i <vectorsSize; i++){
            sum += pow(calcDiff(p[i], q[i]),k);
        }
    }
    return pow(sum, 1/k);
}

/// @brief Calculates Eclidean distance.
/// @param p vector one.
/// @param q vector two.
/// @return the calculate result.
double DistanceType::disEclidean(vector<double> p, vector<double> q){
    return disMinkowski(p, q, P_ECLIDEAN);
}


/// @brief Calculates Manetam- Geometrydistance.
/// @param p vector 1.
/// @param q vector 2.
/// @return the calculate result.
double DistanceType::disGeometry(vector<double> p, vector<double> q) {
    return disMinkowski(p, q, P_GEOMETRY);
}


/// @brief Calculates hebyshev distance.
/// @param p vector 1.
/// @param q vector 2.
/// @return the calculate result.
double DistanceType::chebyshevDistance(vector<double> p, vector<double> q){
    if (!CheckFuncs::checkSameLenght(p,q)){
        return 0;
    }
    double num, temp;
    double maxNum = calcDiff(p[0],q[0]);

    for (int i = 1; i < p.size(); i++) {
    num = calcDiff(p[i],q[i]);
    if (num > maxNum) {
        maxNum = num;
    }
    }
    return maxNum;
    }

/// @brief Calculates canberra distance.
/// @param p vector 1.
/// @param q vector 2.
/// @return the calculate result.
double DistanceType::disCanberra(vector<double> p, vector<double> q){
     if (!CheckFuncs::checkSameLenght(p,q)){
        return 0;
    }

    int const vectorsSize = p.size();
    double sum = 0;
    if(vectorsSize == q.size())
    {
        for(int i = 0; i <vectorsSize; i++){
            sum += calcDiff(p[i], q[i])/(abs(p[i]) + abs(q[i]));
        }
    }
    return sum;
} 