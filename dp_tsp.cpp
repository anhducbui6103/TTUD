#include <bits/stdc++.h>
using namespace std;

const int N = 20, INF = 1e9;
int n;
int C[N][N], mem[N][1 << N];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> C[i][j];
}

int dp(int i, int S)
{
    if (S == (1 << n) - 1)
        return mem[i][S] = C[i][0];
    if (mem[i][S] != -1)
        return mem[i][S];
    int res = INF;
    for (int j = 0; j < n; j++)
    {
        if (S & (1 << j))
            continue;
        res = min(res, C[i][j] + dp(j, S | (i << j)));
    }
    return mem[i][S] = res;
}

int main()
{
    memset(mem, -1, sizeof(mem));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    cout << dp(0, 1) << endl;

    return 0;
}