#include <bits/stdc++.h>
using namespace std;

const int N = 100002, M = 17;
int n, k, m;
vector<int> g[N];
int c[M];

void enter() 
{
    cin >> n >> m;
    for (int i=1, u, v; i<=m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> k;
    for (int i=0; i<k; ++i) 
        cin >> c[i];
}

int D[M][N];
const int oo =1e7;
void init( )
{
    memset(D, -1, sizeof(D));
    for (int i=0; i<k; ++i) 
    {
        queue<int> Q;
        Q.push(c[i]);
        D[i][c[i]] = 0;
        int u;
        while (!Q.empty()) 
        {
            u = Q.front(); Q.pop();
            for (int v : g[u]) 
            {
                if (D[i][v] == -1) 
                {
                    D[i][v] = D[i][u] + 1;
                    Q.push(v);
                }
            }
        }
        for (u=1; u<=n; ++u) 
            if (D[i][u] == -1) 
                D[i][u] = oo;
    }
}

int f[1 << M];

int solve() 
{
    for (int i=0; i<(1 << k); ++i) 
    {
        f[i] = oo;
    }
    for (int i=0; i<k; ++i) 
    {
        f[1 << i] = 1;
    }
    for (int i=1, x, y; i<(1 << k) - 1; ++i) 
    {
        for (x=0; x<k; ++x) 
        {
            if ((1 << x) & i)
            for (y=0; y <k ;++ y) 
            {
                if (!((1 << y)  & i))
                {
                    f[i | (1 << y)] = min(f[i | (1 << y)], f[i] + D[x][c[y]]);
                }
            }
        }
    }
    if (f[(1 <<k) - 1] >= oo) 
        return -1;
    return f[(1 << k) - 1];
}

int main() 
{
    ios_base::sync_with_stdio(0);
    enter();
    init();
    cout << solve();
}