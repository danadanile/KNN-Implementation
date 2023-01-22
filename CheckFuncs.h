#ifndef CHECKFUNCS_H_
#define CHECKFUNCS_H_
#include <cstring>
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class CheckFuncs {
    // @brief functions for different checks in the project

public:
    /// @brief count number digits in int
    /// @param number
    /// @return num digits
    static int count_digit(int number);

    /// @param str string
    /// @return true if numeric false otherwise
    static bool isNumeric(string const &str);

    /// @param str k string
    /// @return true if a number positive string
    static bool checkKValid(string k_input);

    /// @brief- Function is number checks if the string is a number.
    /// @param s string from user.
    /// @return true if the string is a number, false otherwise.
    static bool isNumber(string &s);

    /// @brief check same lenght of vector and classifiend vector
    /// @param p vec1
    /// @param q vec2
    /// @return 1 if same lenght, 0 otherwise
    static int checkSameLenght(vector<double> p, vector<double> q);
};
#endif