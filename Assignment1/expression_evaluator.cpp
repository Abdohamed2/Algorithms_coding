#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class ExpressionEvaluator
{
private:
    string s;
    int index;

    long long parseExpression()
    {
        long long result = 0;
        long long number = 0;
        int sign = 1;

        while (index < s.length())
        {
            char c = s[index];

            if (isdigit((unsigned char)c))
            {
                number = parseNumber();
                result += sign * number;
                continue;
            }
            else if (c == '+')
            {
                sign = 1;
            }
            else if (c == '-')
            {
                sign = -1;
            }
            else if (c == '(')
            {
                index++;
                number = parseExpression();
                result += sign * number;
            }
            else if (c == ')')
            {
                return result;
            }

            index++;
        }

        return result;
    }

    long long parseNumber()
    {
        long long num = 0;
        while (index < s.length() && isdigit((unsigned char)s[index]))
        {
            num = num * 10 + (s[index] - '0');
            index++;
        }
        return num;
    }

public:
    long long evaluate(string str)
    {
        s = str;
        index = 0;
        return parseExpression();
    }
};

int main()
{
    ExpressionEvaluator evaluator;

    cout << "first evaluator 1 + 1 = " << evaluator.evaluate("1 + 1") << endl;
    cout << "second evaluator 2-1 + 2 = " << evaluator.evaluate("2-1 + 2 ") << endl;
    cout << "third evaluator = " << evaluator.evaluate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << "4th evaluator is = " << evaluator.evaluate("-(2+3)") << endl;

    return 0;
}
