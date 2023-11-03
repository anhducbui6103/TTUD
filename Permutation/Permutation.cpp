#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
int a[MAXN];
int used = 0;
int n;

void solve(int current)
{
    if (current == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            used = 0;
            for (int j = 0; j < current; j++)
            {
                if (a[j] == i)
                {
                    used = 1;
                    break;
                }
            }
            if (used == 0)
            {
                a[current] = i;
                solve(current + 1);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    solve(0);

    return 0;
}