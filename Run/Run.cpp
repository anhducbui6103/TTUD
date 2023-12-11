#include <bits/stdc++.h>

using namespace std;

int n, res = 1;
const int MAXN = 1e5 + 6;
int A[MAXN];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
}

void run()
{
    for (int i = 0; i < n - 1; i++)
        if (A[i + 1] < A[i])
            res++;
}

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    run();
    cout << res << endl;
    return 0;
}