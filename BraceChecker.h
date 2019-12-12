#pragma once

#include <iostream>
#include <stack>
#include <map>
#include <set>

using namespace std;

class BraceChecker {
public:
    map<char, char> objects;
    static bool isBalanced(const string &str);
};
