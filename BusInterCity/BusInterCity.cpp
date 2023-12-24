#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int INF = 1e9;
int n, m;
int w[N][N], C[N], D[N]; // Ma trận chi phí của đồ thị mới
vector<int> adj[N];      //  Danh sách kề đồ thị cũ
vector<int> dist(N, INF);
vector<int> edge_dist(N, -1);
vector<bool> visited(N, false);
typedef pair<int, int> ii;

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> C[i] >> D[i];
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            w[i][j] = i == j ? 0 : INF;
}

void BFS(int i)
{
    queue<int> Q;
    fill(visited.begin(), visited.end(), false);
    fill(edge_dist.begin(), edge_dist.end(), -1);
    edge_dist[i] = 0;
    Q.push(i);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        visited[u] = true;
        for (const int &v : adj[u])
        {
            if (!visited[v])
            {
                edge_dist[v] = 1 + edge_dist[u];
                if (edge_dist[v] <= D[i])
                {
                    w[i][v] = C[i];
                    Q.push(v);
                }
            }
        }
    }
}

void dijkstra(int s, int t)
{
    priority_queue<ii, vector<ii>, greater<ii>> PQ;
    dist[s] = 0;
    PQ.push(make_pair(0, s));
    while (!PQ.empty())
    {
        int u = PQ.top().second;
        PQ.pop();
        for (int v = 1; v <= n; v++)
        {
            if (w[u][v] != INF && u != v)
            {
                if (dist[v] > dist[u] + w[u][v])
                {
                    dist[v] = dist[u] + w[u][v];
                    PQ.push(make_pair(dist[v], v));
                }
            }
        }
    }
}

void display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << w[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    for (int i = 1; i <= n; i++)
        BFS(i);
    dijkstra(1, n);
    cout << dist[n] << endl;
    // display();
    return 0;
}