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
        if (op.find(ch) != op.end()) {
            st.push(ch);
        } else if (st.empty()) {
            return false;
        } else if ((ch != ')') && (ch != '(') && (ch != '[') && (ch != ']') && (ch != '{') && (ch != '}')) {
            continue;
        } else if ((brack.find(ch) != brack.end()) && (brack.find(ch)->second == st.top())) {
            st.pop();
        } else return false;

    }
     if (st.empty()) {
        return true;
    } else return false;
}
