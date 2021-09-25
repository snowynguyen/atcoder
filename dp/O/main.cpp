#include <bits/stdc++.h>

using namespace std;
#define DEBUG

int n, a[22][22];

const int mod = 1000000007;

int f[1<<21];

int F(int mask)
{
    int i = __builtin_popcount(mask);

    if (i == n)
        return 1;

    if (f[mask] > -1) return f[mask];
    f[mask] = 0;

    for (int j=0; j<n; ++j)
    {
        if (!(mask & (1<<j)))
        {
            if (a[i][j])
            {
                f[mask] += F(mask | (1 << j));
                f[mask] %= mod;
            }
        }
    }
    return f[mask];
}

int main()
{
    #ifdef DEBUG
    freopen("input.txt","r",stdin);
    #endif // DEBUG
    cin >> n;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            cin >> a[i][j];
    for (int j=0; j<(1<<n); ++j)
        f[j] = -1;
    cout << F(0);
    return 0;
}
