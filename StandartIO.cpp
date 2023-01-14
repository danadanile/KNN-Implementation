#include <iostream>
#include "StandartIO.h"

using namespace std;

string StandartIO::read() {
    std::string res;
    getline(std::cin, res);
    return res;
}

void StandartIO::write(const string &str) {
    cout << str;
}