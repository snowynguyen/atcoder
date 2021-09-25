#include <bits/stdc++.h>
using namespace std;

struct BIT 
{
    int n; 
    vector<int > f;

    void init(int n) 
    {
        this->n = n;
        f.assign(n + 1, 0);
    } 

    int get (int p) 
    {
        int r = 0;
        for (;p; p -= p & -p) 
            r += f[p];
        return r;
    }

    int get(int l, int r) 
    {
        return get(r) - get(l - 1);
    }

    void update (int p, int b) 
    {
        for (;p<=n; p += p & -p) 
        {
            f[p] += b;
        }
    }
}bit;

int main() 
{
    int n; cin >> n;
    bit.init(n);
    vector<int> a(n + 1);
    long long r = 0;
    for (int i=1; i<=n; ++i) 
    {
        cin >> a[i];
        ++a[i];
        r += bit.get(a[i] + 1, n);
        bit.update(a[i], 1);
    }
    
    for (int i=1; i<=n; ++i) 
    {
        cout << r << '\n';
        r += (n) - a[i] - a[i] + 1;
    }
}