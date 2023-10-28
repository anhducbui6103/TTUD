#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e9+7;
int n, k;
int mem[999][999];

int C(int k, int n)
{
    if (k == 0 || k == n)
        return mem[k][n] = 1;
    if (mem[k][n] != -1)
        return mem[k][n];
    int res = C(k - 1, n - 1) + C(k, n - 1);
    return mem[k][n] = res%MAXN;

}
int main()
{
    memset(mem, -1, sizeof(mem));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n;
    cout << C(k, n) << endl;
    return 0;
}