#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include "CheckFuncs.h"
#include "VectorUnclassified.h"



using namespace std;

VectorUnclassified::VectorUnclassified()
{
}

VectorUnclassified::VectorUnclassified(stringstream &stream) {

    vector<double> vec;
    int vecLength = -1;
    string line, word;
    while (getline(stream, line)) {
        stringstream str(line);
        vec.clear();
        while (getline(str, word, ',')) {
            if (CheckFuncs::isNumber(word) == 1) {
                vec.push_back(stod(word));
            } else {
                throw invalid_argument("Invalid input: file have input that is not a number.");
            }
        }
        if (vecLength == -1) {
            vecLength = vec.size();
        } else if (vec.size() != vecLength) {
            throw invalid_argument("Invalid input: Vector length is not consistent.");
        }
        vecUnclassified.push_back(vec);
    }
}


int VectorUnclassified::getTestLength()
{
    return vecUnclassified.size();
}

int VectorUnclassified::getOneVecLength(){
    return vecUnclassified[0].size();
}
vector<vector<double>> VectorUnclassified::getVecUnclassified()
{
   return vecUnclassified;
}


void VectorUnclassified::deleteTest() {
    vecUnclassified.clear();
    vecUnclassified.shrink_to_fit();

}