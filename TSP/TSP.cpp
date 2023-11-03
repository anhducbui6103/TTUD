#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
int n, cur_cost = 0, otp_cost = 1e6;
int c[MAXN][MAXN], cmin = 1e6;
int x[MAXN], x_otp[MAXN];
bool visited[MAXN] = {false};

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (!visited[v])
        {
            x[k] = v;
            visited[v] = true;
            cur_cost += c[x[k - 1]][v];
            if (k == n)
            {
                if (cur_cost + c[v][1] < otp_cost)
                {
                    otp_cost = cur_cost + c[v][1];
                    for (int i = 1; i <= n; i++)
                        x_otp[i] = x[i];
                }
            }
            else if (cur_cost + (n - k + 1) * cmin < otp_cost)
                Try(k + 1);
            cur_cost -= c[x[k - 1]][v];
            visited[v] = false;
        }
    }
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (i != j)
                if (c[i][j] < cmin)
                    cmin = c[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    x[1] = 1;
    visited[1] = true;
    Try(2);
    cout << otp_cost << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << x_otp[i] << " -> ";
    // cout << 1 << endl;
    return 1;
}