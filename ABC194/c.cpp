#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long ret =0 ;
    long long n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) 
        cin >> a[i];
    for (int i=0; i<n; ++i) 
        ret += a[i] * a[i] * (n - 1);
    long long sum = 0 ;
    for (int i=0; i<n; ++i) 
    {
        ret -= 2 * sum * a[i];
        sum += a[i];
    }
    cout << ret;
}