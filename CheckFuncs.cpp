#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "CheckFuncs.h"


int CheckFuncs::count_digit(int number) {
    int count = 0;
    while(number != 0) {
        number = number / 10;
        count++;
    }
    return count;
}



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


int CheckFuncs::checkSameLenght(vector<double> p, vector<double> q){
    if(p.size() == q.size()){
        return 1;
    }
    else{
        return 0;
    }
}
