#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int o=0,e=0; string t;
    for (int c=0,i=1; i<=n; ++i) 
    {
        c=0;
        cin >> t;
        for (int j =0; j < m; ++j) 
        {
            c += t[j] & 1;
        }
        if (c & 1) 
            ++o;
        else 
            ++e;
    }
    cout << (long long) e * o;
}