#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e9 + 7;  // số phần tử tối đa
vector<int> adj[N];        // mảng adj gồm N vector :D?
vector<int> compID(N, -1); // vector N phần tử, mỗi phần tử có gt ban đầu là -1
int mem[999][999];         // mảng 2 chiều, chắc thế
const int MOD = 1e9+7;     // nhiều bài sẽ tính theo MOD thì tính đoạn nào mình đều %= là được
bool precedence[MAXN][MAXN] = {false};

bool compare(int a, int b)
{
    return abs(a) < abs(b);
}

int main()
{
    memset(mem, -1, sizeof(mem)); // khởi tạo giá trị ban đầu của mảng là -1 :D
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    adj[u].push_back(v); // push_back của vector
    adj[v].push_back(u);
    for (int u = 1; u <= n; u++)
    {
        sort(adj[u].begin(), adj[u].end(), compare);  // sort :D với điều kiện của compare
    }
    return 0;
}