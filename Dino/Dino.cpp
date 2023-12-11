#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 5;
int n;
int A[MAXN];
queue<int> H;
stack<int> C;
string str;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = n - 1; i >= 0; i--)
        C.push(A[i]);
    cin >> str;
}

void dino()
{
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if (c == 'C')
        {
            if (!C.empty())
            {
                int a = C.top();
                C.pop();
                H.push(a);
            }
        }
        else if (c == 'H')
        {
            if (!H.empty())
            {
                int a = H.front();
                H.pop();
                C.push(a);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    dino();
    while (!C.empty())
    {
        cout << C.top() << " ";
        C.pop();
    }
    return 0;
}