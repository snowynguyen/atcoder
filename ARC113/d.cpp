#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int pw(int a, int b) 
{
    if (b == 0) 
        return 1;
    long long c = pw(a, b / 2);
    c =c * c  % mod;
    if (b % 2 == 1) 
        c = c * a % mod;
    return c;
}

int F(int n, int k) 
{
    return ((pw(k, n) - pw(k - 1, n)) % mod + mod) % mod;
}

int main() 
{
    int m, n, k;
    cin >> n >> m >> k;
    if (n == 1) 
    {
        if (m == 1) 
        {
            cout << k;
        }
        else 
        {
            cout << pw(k, m);
        }
        return 0;
    }
    else if ( m == 1) 
    {
        cout << pw(k, n);
        return 0;
    }
    int r = 0;
    for (int i=1; i<=k; ++i) 
    {
        r = (r + (long long)(pw(i, n) - pw(i - 1, n) + mod) * pw(k - i + 1, m))% mod;
    }
    cout << r;
}