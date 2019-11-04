#include "BraceChecker.h"

bool BraceChecker::isBalanced(const std::string& input)
{
	return !(std::accumulate(input.begin(), input.end(), double(1), [] (double x, char y)
		{
			if (y == '{') { return x*2; }
			if (y == '}') { return x/2; }
			if (y == '[') { return x*3; }
			if (y == ']') { return x/3; }
			if (y == '(') { return x*5; }
			if (y == ')') { return x/5; }
			else { return x; }
		}) - 1);
}