#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <map>
#include <stdexcept>
// #include "DistanceType.h"
#include "CheckFuncs.h"
#include "VectorUnclassified.h"

using namespace std;


VectorUnclassified::VectorUnclassified(){
   
}


/// @brief The class create map by file name. the first column in the map
/// is the vector, the second is the name "".
/// @param fname as a file name.
VectorUnclassified::VectorUnclassified(string fname){
   
   vector<vector<string>> content;
   vector<string> row;
   string line, word;

   fstream file(fname, ios::in);
   if (file.is_open())
   {
      while (getline(file, line))
      {
         row.clear();
         stringstream str(line);

         while (getline(str, word, ','))
            row.push_back(word);
         content.push_back(row);
      }
   }
   else {
      throw invalid_argument("invalid input");////
   }

   vector<double> vec;
   vector<double> vecPrev={};
   string nameType;


   for (int i = 0; i < content.size(); i++)
   {

      for (int j = 0; j < content[i].size(); j++){
         if(CheckFuncs::isNumber(content[i][j])==1)  //checks if the file fills with numbers.
            vec.push_back(stod(content[i][j]));
         else         
            throw invalid_argument("invalid input"); ////  
      } 

      //int jSize = content[i].size() - 1;
      nameType = "";

      if((i == 0) || CheckFuncs::checkSameLenght(vec,vecPrev) == 1) //check the lenght. (do it also in the first iteration.)
        vecUnclassified.insert(pair<vector<double>, string>(vec, nameType));
      else       
         throw invalid_argument("invalid input"); 


      vecPrev = vec;
      // set value to default
      vec = {};
      nameType = "";
   }
}

/// @brief get the number of rows in the map.
/// @return the size map.
int VectorUnclassified::getSizeMap(){
   return vecUnclassified.size();
}

/// @brief return the length of the vector in the map
/// @return the first vector length, which symbolized the rest of vectors.
int VectorUnclassified::GetVectorLength(){
   multimap<vector<double>, string>::iterator itr;
   itr = vecUnclassified.begin();
   return itr->first.size();

}


/// @brief 
/// @param vec vector to find
/// @param nameClassify name to update.
/// @return false if is not find it. 
bool VectorUnclassified::updateString(vector<double> vec, string nameClassify){
    multimap<vector<double>,string>::iterator itr;    
    itr = vecUnclassified.begin();

      itr = vecUnclassified.find(vec);
      if (itr != vecUnclassified.end()){ 
         itr->second=nameClassify;
         return true;
      }
      else
      {
         return false;
      }
}



