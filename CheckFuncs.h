#ifndef CHECKFUNCS_H_
#define CHECKFUNCS_H_
#include <cstring>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class CheckFuncs {
    /// @brief InputCheck type by int.

public:
    static int count_digit(int number);
    static bool isNumeric(string const &str);
    static bool checkKValid(string k_input);
    static bool isNumber(string &s);
};
#endif