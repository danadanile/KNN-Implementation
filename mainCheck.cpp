#include "VectorUnclassified.h"
#include "VectorMap.h"
#include "Cli.h"
#include "DefaultIO.h"
#include "StandartIO.h"
#include "sstream"
using namespace std;
int main(){
    std::string str = "5.4,3.9,1.7,0.4,Iris-setosa\n4.6,3.4,1.4,0.3,Iris-setosa\n5.0,3.4,1.5,0.2,Iris-setosa\n4.4,2.9,1.4,0.2,Iris-setosa\n4.9,3.1,1.5,0.1,Iris-setosa\n5.4,3.7,1.5,0.2,Iris-setosa\n4.8,3.4,1.6,0.2,Iris-setosa\n4.8,3.0,1.4,0.1,Iris-setosa\n";
    std::stringstream ss(str);
    VectorMap vec(ss);
}
    
