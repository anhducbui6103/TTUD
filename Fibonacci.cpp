#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

const int MAXN = 100;
int mem[MAXN];
int n;

int fib(int n)
{
    if (n <= 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int fib_dp(int n)
{
    if (n <= 2)
        return 1;
    if (mem[n] != -1)
        return mem[n];

    int res = fib_dp(n - 1) + fib_dp(n - 2);
    return mem[n] = res;
}

int main()
{
    memset(mem, -1, sizeof(mem));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    auto start = high_resolution_clock::now();
    // cout << fib(n) << endl;
    cout << fib_dp (n) << endl;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << duration.count() << endl;
    return 0;
}
