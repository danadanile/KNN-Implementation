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
    disName="AUC";
    disType=1;
    train = VectorMap();
    test= VectorUnclassified();
    k=5;
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
    return train;
}

VectorUnclassified Data::getTest() {
    return test;
}

