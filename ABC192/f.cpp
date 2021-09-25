#include <bits/stdc++.h>
using namespace std;

int n;
long long x;
const int N = 102;
int a[N];

void maxi(long long &a, long long b) 
{
    if (b > a) 
        a = b;
}

void enter() 
{
    cin >> n >> x;
    for (int i=1; i<=n; ++i) 
        cin >> a[i];
}

long long f[N][N][N][N];

void init() 
{
    for (int k=2; k<=n; ++k) 
    {
        for (int i=0; i<=n; ++i) 
        {
            for (int c=0; c<=n; ++c) 
            {
                for (int r=0; r<n; ++r) 
                {
                    f[k][i][c][r] = -1e18;
                }
            }
        }
    }
    for (int k=2; k<=n; ++k) 
    {
        for (int i=0; i<=n; ++i)
            f[k][i][0][0] = 0;

        for (int i=1; i<=n; ++i) 
        {
            for (int c=1; c<=n; ++c) 
            {
                for (int r=0; r<n; ++r) 
                {
                    maxi(f[k][i][c][r], f[k][i-1][c-1][(r - a[i] % k + k) % k] + a[i]);
                    maxi(f[k][i][c][r], f[k][i-1][c][r]);
                }
            }
        }
    }
}

void solve() 
{
    long long ret = 0;
    for (int i=1; i<=n; ++i) 
    {
        ret = max(ret, (long long)a[i]);
    }
    ret = x - ret;
    for (int k=2; k<=n; ++k) 
    {
        if (f[k][n][k][x % k] > 0) 
        {
            ret = min(ret, (x - f[k][n][k][x % k]) / k);
        }
    }
    cout << ret;
}

int main() 
{
    enter();
    init();
    solve();
}