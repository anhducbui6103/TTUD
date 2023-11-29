#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> compID(N, -1);
int n, m, curID = 0;

void input()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int u = 1; u <= n; u++)
    {
        sort(adj[u].begin(), adj[u].end());
    }
}

void dfs(int u)
{
    compID[u] = curID;
    for (const int &v : adj[u])
    {
        if (compID[v] == -1)
        {
            dfs(v);
        }
    }
}

int main()
{
    input();
    for (int u = 1; u <= n; u++)
    {
        if (compID[u] == -1)
        {
            curID++;
            dfs(u);
        }
    }
    cout << curID;
    return 0;
}