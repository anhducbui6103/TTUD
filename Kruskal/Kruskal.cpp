#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e4 + 5;
int n, m;

struct edge
{
    int u, v, w;
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

vector<edge> edges;

struct UnionFind
{
    vector<int> parent;
    UnionFind(int n)
    {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        else
            return parent[x] = Find(parent[x]);
    }

    void Unite(int x, int y)
    {
        parent[Find(x)] = Find(y);
    }
};

bool edgeCMP(const edge &a, const edge &b)
{
    return a.w < b.w;
}

vector<edge> Kruskal(int n, vector<edge> edges)
{
    sort(edges.begin(), edges.end(), edgeCMP);
    UnionFind uf(n);
    vector<edge> res;
    for (const auto &e : edges)
    {
        int u = e.u, v = e.v, w = e.w;
        if (uf.Find(u) != uf.Find(v))
        {
            res.push_back(e);
            uf.Unite(u, v);
        }
    }
    return res;
}

void input()
{
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edges.push_back(edge(u - 1, v - 1, w)); // Adjust for 0-indexing
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int count = 0;
    input();
    vector<edge> res = Kruskal(n, edges);
    for (const auto &e : res)
    {
        count += e.w;
        // cout << e.u + 1 << ' ' << e.v + 1 << ' ' << e.w << endl; // Adjust for 1-indexing
    }
    cout << count << endl;
    return 0;
}
