#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n; cin >> n;
    long long r = 1e18;
    for (int i=1; i<=n; ++i) 
    {
        int a, p, x; cin >> a >> p >> x;
        if (x > a) 
        {
            r = min(r, (long long)p);
        }
    }
    if (r == 1e18) 
        r = -1;
    cout << r;
}