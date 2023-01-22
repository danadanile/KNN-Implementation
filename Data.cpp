#include <iostream>  
#include <cstring>  
#include <vector>  
#include <cmath>
#include <sstream>
#include "Data.h"
#include "VectorMap.h"
#include "DistanceType.h"
using namespace std; 


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
void Data::setTrain(stringstream &fname){
    train = new VectorMap(fname);
}

void Data::setTest(stringstream &fname){
    test = new VectorUnclassified(fname);
}

bool Data::getTrainIsInit() {
 return trainIsInit;
}

bool Data::getTestIsInit() {
 return testIsInit;
}

bool Data::getIsClassified() {
 return isClassified;
}

void Data::setTrainIsInit(bool b){
    trainIsInit=b;
}

void Data::setTestIsInit(bool b){
    testIsInit=b;
}

void Data::classifyData() {
    test->classify(train, k, disType);
}

void Data::SetIsClassified(bool b) {
    isClassified=b;
}


