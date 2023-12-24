#include<bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int> &x, int c) {
    int count = 1;
    int last = x[0];
    for (int i = 1; i < x.size(); i++) {
        if (x[i] - last >= mid) {
            last = x[i];
            count++;
        }
    }
    return count >= c;
}

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x.begin(), x.end());
    int l = 0;
    int r = x[n-1] - x[0] + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid, x, c))
            l = mid;
        else
            r = mid;
    }
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}


// tle