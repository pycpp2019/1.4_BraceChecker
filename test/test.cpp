#include <iostream>
#include <sstream>

#include <vector>
#include <string>
#include <stack>
#include <functional>
#include <utility>

#include "rng.hh"

#include <BraceChecker.h>


static const std::pair<char, char> BRACES[3] = {
    std::make_pair('(',')'),
    std::make_pair('{','}'),
    std::make_pair('[',']')
};

static std::pair<char, char> random_brace(Rng *rng) {
    return BRACES[rng->rand_int() % 3];
}

static std::string random_sequence(Rng *rng, int min_len) {
    std::stack<char> st;
    std::string seq;
    for (int i = 0; i < min_len || !st.empty(); ++i) {
        double p = 1.0 - double(i)/(min_len - 1);
        if (st.empty() || rng->uniform() < p) {
            std::pair<char, char> p = random_brace(rng);
            seq.push_back(p.first);
            st.push(p.second);
        } else {
            seq.push_back(st.top());
            st.pop();
        }
    }
    return seq;
}

static const int ATTEMPTS = 16;

int main() {
    std::vector<std::pair<std::string, std::function<bool(Rng*)>>> tests;
    std::vector<std::pair<std::string, bool>> cases = {
        std::make_pair("", true),
        std::make_pair("(", false),
        std::make_pair(")", false),
        std::make_pair("()", true),
        std::make_pair("(}", false),
        std::make_pair("{()}", true),
        std::make_pair("({)}", false),
        std::make_pair("[({})]", true),
        std::make_pair("[(]{)}", false),
        std::make_pair("{ab}", true),
        std::make_pair("{ }", true),
    };
    for (std::pair<std::string, bool> p : cases) {
        std::stringstream ss;
        ss << "'" << p.first << "'";
        tests.push_back(std::make_pair(ss.str(), [p](Rng *rng) -> bool {
            return BraceChecker::isBalanced(p.first) == p.second;
        }));
    }
    for (int n = 10; n <= 1000000; n *= 10) {
        std::stringstream ss;
        ss << "random good " << n;
        tests.push_back(std::make_pair(ss.str(), [n](Rng *rng) -> bool {
            for (int i = 0; i < ATTEMPTS; ++i) {
                std::string seq = random_sequence(rng, n);
                if (!BraceChecker::isBalanced(seq)) {
                    return false;
                }
            }
            return true;
        }));
        ss.str("");
        ss << "random bad  " << n;
        tests.push_back(std::make_pair(ss.str(), [n](Rng *rng) -> bool {
            for (int i = 0; i < ATTEMPTS; ++i) {
                std::string seq = random_sequence(rng, n);
                seq[rng->rand_int() % seq.size()] = ' ';
                if(BraceChecker::isBalanced(seq)) {
                    return false;
                }
            }
            return true;
        }));
    }

    Rng rng(0xDEADBEEF);

    int total = tests.size();
    int failed = 0;
    int counter = 0;

    for (std::pair<std::string, std::function<bool(Rng*)>> &pair : tests) {
        std::cout << "(" << counter << "/" << total << ") ";
        std::cout << pair.first << " ... " << std::flush;

        bool ok;
        try {
            ok = pair.second(&rng);
        } catch (...) {
            ok = false;
            std::cout << "unexpected exception caught" << std::endl;
        }

        if (ok) {
            std::cout << "ok";
        } else {
            failed += 1;
            std::cout << "fail";
        }
        std::cout << std::endl;
        counter += 1;
    }

    int ret = 0;
    std::cout << "result: ";
    if (failed > 0) {
        std::cout << "fail";
        ret = 1;
    } else {
        std::cout << "ok";
    }
    std::cout << ". " << total - failed << " passed, " << failed << " failed." << std::endl;

    return ret;
}
