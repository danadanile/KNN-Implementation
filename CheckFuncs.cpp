// @brief functions for different checks in the project
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <vector>
#include <sstream>
#include <string>
#include <stdlib.h> 
#include "CheckFuncs.h"


/// @brief count number digits in int
/// @param number 
/// @return num digits
int CheckFuncs::count_digit(int number) {
    int count = 0;
    while(number != 0) {
        number = number / 10;
        count++;
    }
    return count;
}


/// @param str string 
/// @return true if numeric false otherwise
bool CheckFuncs::isNumeric(string const &str){
    auto it = str.begin();
    while(it !=str.end() && isdigit(*it)) {
        it++;
    }
    return !str.empty() && it==str.end();
}


bool CheckFuncs::checkKValid(string k_input){
    if(isNumeric(k_input)) {
        int k = stoi(k_input);
        if(k<=0){
            return false; 
        }
    }
    else{
        return false; 
    }
    return true;
}

/// @brief- Function is number checks if the string is a number.
/// @param s string from user. 
/// @return true if the string is a number, false otherwise.
bool CheckFuncs::isNumber(string &s){
    double ld;
    if (s == "")
    {
        return false;
    }
    if (s == "." || s == "-" || s =="-."|| s ==".-"|| s.size()>301){
        return false;
    }
    return ((istringstream(s) >> ld >> std::ws).eof());
}

/// @brief check same lenght of vector and classifiend vector
/// @param p vec1
/// @param q vec2
/// @return 1 if same lenght, 0 otherwise
int CheckFuncs::checkSameLenght(vector<double> p, vector<double> q){
    if(p.size() == q.size()){
        return 1;
    }
    else{
        return 0;
    }
}
