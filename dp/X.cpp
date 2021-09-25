#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
struct TW 
{
    int w,s,v;

    bool operator  < (const TW &h) const 
    {
        if (s!=h.s)return s < h.s;
        if (w!=h.w)return w < h.w;
        return v  > h.v;
    }
} a[N];
int n;

#define lint long long 
lint f[20001], f_[20001];

int main() 
{
    cin >> n;
    for (int i=1; i<=n; ++i) 
    {
        cin >> a[i].w >> a[i].s >> a[i].v;
        a[i].s += a[i].w;
    }
    sort (a+1, a+1+n);
    for (int i=1; i<=n; ++i) 
    {
        for (int j=a[i].w ; j <= a[i].s; ++j) 
            f_[j] = f[j - a[i].w] + a[i].v;
        for (int j=1; j<=20000; ++j)    
            f[j] = max(f[j], f_[j]);
    }
    lint ans = 0;
    for (int i=1; i<=20000; ++i) 
        ans = max(ans, f[i]);
    cout << ans;
}