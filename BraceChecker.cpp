#include "BraceChecker.h"
#include <iostream>
#include <stack>
#include <map>
#include <set>

using namespace std;

bool BraceChecker::isBalanced(const string &str) {
    stack<char> st;
    map<char, char> brack {
        {')', '('}, {']', '['}, {'}', '{'}
    };
    set<char> op {'(', '[', '{'};
    for (char ch : str) {
        if (op.find(ch) == op.end()) {
            st.push(ch);
        } else if (brack.find(ch) != st.top()) {
            return false;
        } else st.pop();
        if (st.empty()) {
            return true;
        } else return false;
    }
}
