#include <bits/stdc++.h>
using namespace std;

string key;
stack<int> hehe;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        int num;
        cin >> key;
        if (key == "PUSH")
        {
            cin >> num;
            hehe.push(num);
        }
        if (key == "POP")
        {
            if (hehe.size() == 0)
                cout << "NULL" << endl;
            else
            {
                num = hehe.top();
                hehe.pop();
                cout << num << endl;
            }
        }
        if (key == "#")
            break;
    }
    return 0;
}