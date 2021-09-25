#include <bits/stdc++.h>

using namespace std;

#define DEBUG
#define N 3001

int n; char c[N];
int f[N][N];

const int mod = 1000000007;

int solve()
{
    f[1][1] = 1;

    for (int i=2; i<=n; ++i)
    {
        if (c[i-1] == '<')
        {
            int p = f[i-1][1];
            for (int j=2; j<=i; ++j)
            {
                f[i][j] = p;
                p = (p + f[i-1][j]) % mod;
            }
        }
        else
        {
            int p = 0;
            for (int j=n; j>=1; --j)
            {
                p = (p + f[i-1][j]) % mod;
                f[i][j] = p;
            }
        }
    }

    int rr = 0;
    for (int i=1; i<=n; ++i)
        rr = (rr + f[n][i]) %mod;
    return rr;
}

int main()
{
    #ifdef DEBUG
    freopen("t.txt","r",stdin);
    #endif // DEBUG

    scanf ("%d %s", &n, c+1);
    cout << solve();
    return 0;
}
