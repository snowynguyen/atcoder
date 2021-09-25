#include <bits/stdc++.h>
using namespace std;

vector<int> a,r,f;
int n;
const int mod =998244353;

int pw (int a, int b) 
{
    if (b == 0)
        return 1;
    long long c = pw(a, b / 2);
    c = c * c % mod;
    if (b % 2 == 1) 
    {
        c = c * a % mod;
    }
    return c;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    a.resize(n + 1);
    r=f=a;
    
    for (int i=1; i<=n; ++i) 
        cin >> a[i];
    r[n] = a[n];
    for (int i = n - 1; i>=1; --i) 
        r[n] = r[n + 1] * (long long) a[i] % mod;


    long long cw = a[1];
    for (int i=2; i<=n; ++i) 
    {
        if (a[i - 1] <= a[i])
        {
            cw = (cw *a[i]) % mod;
        }
        else 
        {
            
        }
    }
    
}