#include <bits/stdc++.h>
using namespace std;

const int MAX_T = 15;
const int MAX_N = 105;
int t, n, m;
int A[MAX_N], B[MAX_N];
int res[MAX_T];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A, A + n);
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> B[i];
    sort(B, B + m);
}

void output()
{
    for (int i = 1; i < t; i++)
        cout << res[i] << endl;
    cout << res[t];
}

int solve()
{
    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m)
    {
        if (A[i] == B[j])
        {
            cnt++;
            i++;
            j++;
        }
        else if (A[i] < B[j])
            i++;
        else
            j++;
    }
    return cnt;
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