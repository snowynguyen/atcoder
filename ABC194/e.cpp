#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> c(n + 1), d(n + 1);
    for (int i=1; i<=n; ++i) 
    {
        cin >> a[i];
    }

    set<int> S;
    for (int i=0; i<=n; ++i) 
        S.insert(i);

    d[0] = n;
    for (int i=1; i<m; ++i) 
    {
        d[c[a[i]]]--;
        if (c[a[i]] == 0) 
            S.erase(a[i]);
        c[a[i]]++;
        d[c[a[i]]]++;
    }

    int ret = m;

    for (int i=m; i <=n; ++i) 
    {
        d[c[a[i]]]--;
        if (c[a[i]] == 0) 
            S.erase(a[i]);
        c[a[i]]++;
        d[c[a[i]]]++;
        ret = min(ret, *S.begin());
        c[a[i - m + 1]] --;
        if (c[a[i-m+1]] == 0)   
            S.insert(a[i -m + 1]);
    }
    cout << ret;

}