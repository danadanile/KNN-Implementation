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
Data::Data():disName("AUC"),disType(1),train(new VectorMap()), test(new VectorUnclassified()){ 
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

void Data::setDisType(int newDisType){
    disType=newDisType;
}

int Data::getk() {
    return k;
}

VectorMap* Data::getVectorMap() {
    return train;
}

VectorUnclassified* Data::getTest() {
    return test;
}

void Data::setTrain(string fname){
    delete train;
    train = new VectorMap(fname);
}

void Data::setTest(string fname){
    delete test;
    test = new VectorUnclassified(fname);
}

bool Data::getTrainIsInit() {
 return trainIsInit;
}

bool Data::getTestIsInit() {
 return testIsInit;
}

void Data::setTrainIsInit(){
    trainIsInit=true;
}

void Data::setTestIsInit(){
    testIsInit=true;
}

