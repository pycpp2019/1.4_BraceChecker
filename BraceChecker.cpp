#include <stack>

#include <BraceChecker.h>

static bool is_opening(char c) {
    return c == '(' || c == '{' || c == '[';
}

static bool is_closing(char c) {
    return c == ')' || c == '}' || c == ']';
}

static char get_closing(char br) {
    switch (br) {
        case '(': return ')';
        case '{': return '}';
        case '[': return ']';
    }
    return '\0';
}

bool BraceChecker::isBalanced(const std::string &seq) {
    std::stack<char> st;
    for (char c : seq) {
        if (is_opening(c)) {
            st.push(get_closing(c));
        } else if (is_closing(c)) {
            if (st.size() > 0 && st.top() == c) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}
