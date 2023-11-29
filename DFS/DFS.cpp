#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
vector<bool> visited(1001, false);
int n, m;

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
    cout << u << ' ';
    visited[u] = true;

    for (const int &v : adj[u])
        if (!visited[v])
        {
            dfs(v); 
        }
}

int main()
{
    input();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    return 0;
    // Sau đó có thể từ DFS để giải một số bài toán khác
}