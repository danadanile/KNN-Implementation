#include "VectorUnclassified.h"
#include "VectorMap.h"
#include "Cli.h"
#include "DefaultIO.h"
#include "StandartIO.h"
using namespace std;
int main(int argc, char **argv){

  DefaultIO *dio = new StandartIO();
  Cli cli(dio);
  cli.start();

//    cout<<"ok1"<<endl;
//    string fname1= argv[1];
//    string fname2= argv[2];
//    VectorMap vec(fname1);
//    cout<<"ok2"<<endl;
//    VectorUnclassified mapObj(fname2);

    // multimap<vector<double>,string> myMap;
    // // add key-value pairs to the map

    // for (auto it = myMap.begin(); it != myMap.end(); ++it) {
    //     cout << "Vector: ";
    //     for (const auto &i : it->first) {
    //         cout << i << " ";
    //     }
    // }
}
 