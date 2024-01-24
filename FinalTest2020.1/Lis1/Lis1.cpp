#include <bits/stdc++.h>

using namespace std;

const int MAX_T = 15;
const int MAX_N = 1e5 + 6;
const int MAX_A = 1e9 + 5;

int A[MAX_N];
int res[MAX_T];
int n, t;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
}

void output()
{
    for (int i = 1; i < t; i++)
        cout << res[i] << endl;
    cout << res[t];
}

int solve()
{
    vector<int> B(MAX_N, 0);
    int max_len = 0;
    for (int i = 0; i < n; i++)
    {
        B[A[i]] = B[A[i] - 1] + 1;
        if (B[A[i]] > max_len)
            max_len = B[A[i]];
    }
    return max_len;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int z = 1; z <= t; z++)
    {
        input();
        res[z] = solve();
    }
    output();
}