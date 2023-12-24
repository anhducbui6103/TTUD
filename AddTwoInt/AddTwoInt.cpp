#include <bits/stdc++.h>
using namespace std;

string a, b, sum;

void Add()
{
    int c=0;
    //     for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0 || carry > 0; --i, --j) {

    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || c > 0; i--, j--)
    {
        int d1, d2;
        d1 = (i >= 0) ? (a[i] - '0') : 0;
        d2 = (j >= 0) ? (b[j] - '0') : 0;
        int s = d1 + d2 + c;
        c = s / 10;
        sum.push_back((s % 10) + '0');
    }
    reverse(sum.begin(), sum.end());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    Add();
    cout << sum;
    return 0;
}