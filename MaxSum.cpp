#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;
int a[MAXN];
int mem[MAXN];
int n;

int dp(int i)
{
    if (i == 1)
        return a[1];
    if (mem[i] != -1)
        return mem[i];
    int res = max(a[i], a[i] + dp(i - 1));
    return mem[i] = res;
}

int solve()
{
    int ans = a[1];
    for (int i = 1; i <= n; i++)
    {
        if (ans < dp(i))
            ans = dp(i);
    }
    return ans;
}

int main()
{
    memset(mem, -1, sizeof(mem));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << solve() << endl;
    return 0;
}