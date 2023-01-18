#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <stdexcept>
#include <iostream>  
#include<string>  

#include "DisplayCommand.h"
#include "VectorUnclassified.h"

using namespace std;  

DisplayCommand::DisplayCommand(DefaultIO *my_dio, Data *my_data) : Command(my_dio, my_data){
    this->description = "4. display results";
}

void DisplayCommand::execute(){
    multimap<vector<double>, string> vecShow=data->getTest()->getVecUnclassified();
    try{
        //add checks!!!!!!!!!!!!!!! :

        // if(data->classifyData==false){
        //     throw invalid_argument("please classify the data");
        // }
        // if(data->getTest???==false){
        //     throw invalid_argument("please classify the data");
        // }
        string sResult="";
        int count = 1;
        for (auto it = vecShow.begin(); it != vecShow.end(); ++it) {
            sResult += to_string(count);
            sResult += " ";
            sResult += it->second;
            sResult += "\n";

                count++;
        }
        sResult += "Done.\n";
        dio->write(sResult);


    }
    catch (const invalid_argument &er){
        dio->write(er.what());
        return;
    }

    


}
