#include <iostream>
#include <sstream>

#include <vector>
#include <string>
#include <stack>
#include <functional>
#include <utility>
#include <random>

#include "test_runner.h"
#include <BraceChecker.h>


static const std::pair<char, char> BRACES[3] = {
    std::make_pair('(',')'),
    std::make_pair('{','}'),
    std::make_pair('[',']')
};

template <typename Generator>
static int rand_int(Generator &rng, int max_n) {
    return std::uniform_int_distribution<>(0, max_n - 1)(rng);
}

template <typename Generator>
static std::pair<char, char> random_brace(Generator &rng) {
    return BRACES[rand_int(rng, 3)];
}

template <typename Generator>
static std::string random_sequence(Generator &rng, int min_len) {
    std::stack<char> st;
    std::string seq;
    std::uniform_real_distribution<> uniform(0.0, 1.0);
    for (int i = 0; i < min_len || !st.empty(); ++i) {
        double p = 1.0 - double(i)/(min_len - 1);
        if (st.empty() || uniform(rng) < p) {
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
    std::minstd_rand rng(0xDEADBEEF);
    TestRunner tr;

    std::vector<std::pair<std::string, bool>> cases = {
        std::make_pair("", true),
        std::make_pair("(", false),
        std::make_pair(")", false),
        std::make_pair("()", true),
        std::make_pair("(}", false),
        std::make_pair("{()}", true),
        std::make_pair("{[])", false),
        std::make_pair("[({})]", true),
        std::make_pair("[(]{)}", false),
        std::make_pair("[{([][])}[]]", true),
        std::make_pair("{ab}", true),
        std::make_pair("{ }", true),
    };
    tr.RunTest([&cases]() {
        for (std::pair<std::string, bool> p : cases) {
            ASSERT_EQUAL(BraceChecker::isBalanced(p.first), p.second);
        }
    }, "examples");

    tr.RunTest([&rng]() {
        for (int n = 10; n <= 1000000; n *= 10) {
            for (int i = 0; i < ATTEMPTS; ++i) {
                std::string seq = random_sequence(rng, n);
                ASSERT(BraceChecker::isBalanced(seq));

                seq[rand_int(rng, seq.size())] = ' ';
                ASSERT(!BraceChecker::isBalanced(seq));
            }
        }
    }, "random");
}
