#include <iostream>  
#include <cstring>  
#include <vector>  
#include <cmath>
#include <sstream>
#include "Data.h"
#include "VectorMap.h"
#include "DistanceType.h"
using namespace std; 

/// @brief Class which calculates the distance by her type.
/// @param disType by int (which simbolaized distance name by enum).
Data::Data(){ 

}

Data::Data(string fname, string disName, int k, DistanceType disType) : vec(fname), 
 disName(disName), k(k), disType(disType) {
}


string Data::getDisName() {
 return disName;
}

void Data::setK(int newK){
    k=newK;
}

void Data::setDisName(string newDisName){
    disName=newDisName;
}

void Data::setDisType(DistanceType newDisType){
    disType=newDisType;
}

int Data::getk() {
    return k;
}

VectorMap Data::getVectorMap() {
    return vec;
}

