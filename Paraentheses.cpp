#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int res = 1;
    string str;
    cin >> str;
    stack<char> stack;

    for (char c : str)
    {
        if (c != '(' && c != ')' && c != '[' && c != ']' && c != '{' && c != '}')
            res = 0;
        if (c == '(' || c == '[' || c == '{')
        {
            stack.push(c);
        }
        if (c == ')')
        {
            if (!stack.empty() && stack.top() == '(')
            {
                stack.pop();
            }
            else
            {
                res = 0;
                break;
            }
        }
        if (c == ']')
        {
            if (!stack.empty() && stack.top() == '[')
            {
                stack.pop();
            }
            else
            {
                res = 0;
                break;
            }
        }
        if (c == '}')
        {
            if (!stack.empty() && stack.top() == '{')
            {
                stack.pop();
            }
            else
            {
                res = 0;
                break;
            }
        }
    }
    if (!stack.empty())
        res = 0;
    cout << res;
    return 0;
}