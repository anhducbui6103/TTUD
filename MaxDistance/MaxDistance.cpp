#include <bits/stdc++.h>
using namespace std;

int number_test_case;
int const MAX = 1e5 + 5;
int n, c;
int x[MAX];

void input()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> x[i];
}

int PrintMaxDistance(){}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> number_test_case;
    for (int v = 0; v < number_test_case; v++)
    {
        input();
        cout << n;
    }
}
