#include <bits/stdc++.h>
using namespace std;

struct TE 
{
    int v, w;
};

const int N = 2001, oo = 1e9;
vector<TE> g[N];
int n, m;
int W[N][N];

void enter() 
{
    cin >> n >> m;
    for (int i=1, u, v, w; i<=m; ++i) 
    {
        cin >>u >> v >> w;
        if (W[u][v]) 
        {
            if (W[u][v] > w) 
                W[u][v] = w;
        }
        else 
            W[u][v] = w;
        g[u].push_back({v, w});
    }
}

int f[N][N];
bool done[N][N];

void dijsktra (int s) 
{
    priority_queue<pair<int, int> , vector<pair<int, int> > , greater <pair <int,int> > > heap;
    heap.push({0, s});
    while (!heap.empty()) 
    {
        auto u = heap.top();
        heap.pop();
        for (auto v : g[u.second]) 
        {
            if (f[s][v.v] > u.first + v.w) 
            {
                f[s][v.v] = u.first + v.w;
                heap.push({f[s][v.v], v.v});
            }
        }
    }
}

void init() 
{
    for (int i=1; i<=n; ++i) 
    {
        for (int j=1; j<=n; ++j) 
            f[i][j] = oo;
        f[i][i] = 0;
    }
    for (int i=1 ;i<=n; ++i) 
    {
        dijsktra(i);
    }
}

void solve() 
{
    for (int u=1; u<=n; ++u) 
    {
        int r = oo;
        if (W[u][u] > 0) 
            r = W[u][u];
        for (int v=1; v<=n; ++v) 
        {
            if (u != v) 
            {
                r = min(r, f[u][v] + f[v][u]);
            }
        }
        if (r >= oo) 
            r = -1;
        cout << r << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    enter();
    init();
    solve();
}