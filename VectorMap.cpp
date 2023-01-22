#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <stdexcept>
#include "DistanceType.h"
#include "CheckFuncs.h"
#include "VectorMap.h"

using namespace std;

VectorMap::VectorMap()
{
}


VectorMap::VectorMap(stringstream &stream)
{

   vector<vector<string>> content;
   vector<string> row;
   string line, word;

   //
   // fstream file(fname, ios::in);
   while (getline(stream, line))
   {
      //getline(ss, key, ',')
      row.clear();
      stringstream str(line);

      while (getline(str, word, ',')){
         if(word==""){
            throw invalid_argument("invalid input");
         }
         row.push_back(word);
      }
      content.push_back(row);
   }


   vector<double> vec;
   vector<double> vecPrev = {};
   string nameType;

   for (int i = 0; i < content.size(); i++)
   {
      for (int j = 0; j < content[i].size() - 1; j++)
      {
         if (CheckFuncs::isNumber(content[i][j]) == 1) // checks if the content is numbers.
            vec.push_back(stod(content[i][j]));
         else
            throw invalid_argument("invalid input: The file should be filled with valid vectors.");
      }

      int jSize = content[i].size() - 1;
      nameType = content[i][jSize];

      if ((i == 0) || CheckFuncs::checkSameLenght(vec, vecPrev) == 1) // check the lenght. (do it also in the first iteration.)
         mapi.insert(pair<vector<double>, string>(vec, nameType));
      else
         throw invalid_argument("invalid input: The vectors in the file should be in the same lenght.");

      vecPrev = vec;
      // set value to default
      vec = {};
      nameType = "";
   }
}


int VectorMap::getSizeMap()
{
   return mapi.size();
}


int VectorMap::GetVectorLength()
{
   multimap<vector<double>, string>::iterator itr;

   itr = mapi.begin();
   return itr->first.size();
}


string VectorMap::knnFunc(vector<double> vecGet, int disNum, int k)
{

   DistanceType disType(disNum);
   double distanceInMap = 0;

   multimap<double, string> distanceMap;
   multimap<vector<double>, string>::iterator itr;

   itr = mapi.begin();
   if (CheckFuncs::checkSameLenght(vecGet, itr->first) == 1)
   { // check if vecGet lenght is valid.

      for (itr = mapi.begin(); itr != mapi.end(); itr++)
      {
         distanceInMap = disType.calcDistanceType(vecGet, itr->first);
         distanceMap.insert(pair<double, string>(distanceInMap, itr->second));
      }

      map<string, int> mapKnn; // name and count
      multimap<double, string>::iterator iterDis;
      map<string, int>::iterator iterKnn;

      iterDis = distanceMap.begin();
      for (int i = 0; i < k; i++)
      {
         iterKnn = mapKnn.find(iterDis->second);
         if (iterKnn == mapKnn.end())
         { // if string not in mapKNN.
            mapKnn.insert(pair<string, int>(iterDis->second, 1));
         }
         else
         {
            iterKnn->second++;
         }
         iterDis++;
      }

      int max = 0;
      string nameMax = "";
      for (iterKnn = mapKnn.begin(); iterKnn != mapKnn.end(); iterKnn++)
      {
         if ((iterKnn->second) > max)
         {
            max = iterKnn->second;
            nameMax = iterKnn->first;
         }
      }
      // cout << nameMax;
      return nameMax;
   }
   return "";
}

multimap<vector<double>, string> VectorMap::getMapi()
{
   return mapi;
}