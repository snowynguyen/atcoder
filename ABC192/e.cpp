#include <bits/stdc++.h>
using namespace std;

const int N = 100002;
#define int long long
struct TFE
{
    int v, t, k;
};
vector<TFE> g[N];
int n, m,s, t;

const long long oo = 1e17;
long long f[N];
bool donef[N];

struct TV
{
    long long w;
    int u;

    bool operator <(const TV& h) const 
    {
        return w > h.w;
    }
};  

signed main() 
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> s >> t;
    for (int i=1, u, v, t, k; i<=m; ++i)
    {
        cin >> u >> v >> t >> k;
        g[u].push_back({v, t, k});
        g[v].push_back({u, t, k});
    }

    priority_queue<TV> heap;
    for (int i=1; i<=n; ++i) 
    {
        f[i] = oo;
    }
    f[s] = 0;
    heap.push({f[s], s});
    while (heap.size()) 
    {
        auto u = heap.top(); heap.pop();
        if (donef[u.u]) continue;
        donef[u.u] = true;
        if (u.u == t) 
            break;
        for (auto v : g[u.u]) 
        {
            long long w = u.w;
            if (w % v.k) 
                w += v.k - w % v.k;
            w += v.t;
            if (f[v.v] > w) 
            {
                f[v.v] = w;
                heap.push({w, v.v});
            }
        }
    }

    if (f[t] >= oo) 
        cout << -1;
    else 
        cout << f[t];

}