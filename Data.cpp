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
Data::Data():disName("AUC"),disType(1),k(5), train(new VectorMap()),
test(new VectorUnclassified()), isClassified(false), testIsInit(false), trainIsInit(false){ 
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

int Data::getK() {
    return k;
}

VectorUnclassified* Data::getTest() {
    return test;
}
VectorMap* Data::getTrain() {
    return train;
}
void Data::setTrain(string fname){
    train = new VectorMap(fname);
}

void Data::setTest(string fname){
    test = new VectorUnclassified(fname);
}

bool Data::getTrainIsInit() {
 return trainIsInit;
}

bool Data::getTestIsInit() {
 return testIsInit;
}

void Data::setTrainIsInit(bool b){
    trainIsInit=b;
}

void Data::setTestIsInit(bool b){
    testIsInit=b;
}

///// @brief
///// @param vec vector to find
///// @param nameClassify name to update.
///// @return false if is not find it.
//void Data::updateString(vector<double> vec, string nameClassify) {
//    multimap<vector<double>, string>::iterator itr;
//
//    itr = test->getVecUnclassified().find(vec);
//    if (itr != test->getVecUnclassified().end()) {
//        itr->second = nameClassify;
//    }
//}

void Data::classify(){
    multimap<vector<double>, string>::iterator it;
    string classification;
    for (it = test->getVecUnclassified().begin(); it != test->getVecUnclassified().end(); it++) {
        classification = train->knnFunc(it->first, disType, k);
       // test->updateString(it->first, classification);
        it->second = classification;
    }
}


//void Data::initForUpload(){
//    trainIsInit=false;
//    testIsInit=false;
//    isClassified=false;
//    delete train;
//    delete test;
//}


