#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int count = 0, last_end = -1;
    typedef pair<int, int> ii;
    cin >> n;
    vector<ii> segments(n);

    for (int i = 0; i < n; i++)
        cin >> segments[i].second >> segments[i].first;

    sort(segments.begin(), segments.end());
    
    for (int i = 0; i < n; i++)
    {
        if (segments[i].second > last_end)
        {
            count++;
            last_end = segments[i].first;
        }
    }
    cout << count << endl;

}