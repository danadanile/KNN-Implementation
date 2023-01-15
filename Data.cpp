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

Data::Data(string fname, int disType, int k) : vec(fname), dis(disType), k(k){
}


DistanceType Data::getDis() {
 return dis;
}

     
int Data::getk() {
    return k;
}

VectorMap Data::getVectorMap() {
    return vec;
}

