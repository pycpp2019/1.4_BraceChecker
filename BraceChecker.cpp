#include "BraceChecker.h"
#include <stack>
#include <iostream>

using namespace std;

bool BraceChecker::isBalanced(const string& string) {
    stack<char> stack;

    for (int i = 0; i < string.length(); i++) {
        if (string[i] == '(' || string[i] == '{' || string[i] == '[') {
            stack.push(string[i]);
            continue;
        }
        if (stack.empty())
            return false;
        switch (string[i])
        {
        case ')':
            if (stack.top() == '(') {
                stack.pop();
                continue;
            }
            else {
                cout << "Not Balanced" << endl;
                return false;
            }
            break;
        case '}':
            if (stack.top() == '{') {
                stack.pop();
                continue;
            }
            else {
                cout << "Not Balanced" << endl;
                return false;
            }
            break;
        case ']':
            if (stack.top() == '[') {
                stack.pop();
                continue;
            }
            else {
                cout << "Not Balanced" << endl;
                return false;
            }
            break;
        default: continue;
        }
    }


    if (stack.empty()) {
        cout << "Balanced" << endl;
        return true;
    }
    else {
        cout << "Not Balanced" << endl;
        return false;
    }
}