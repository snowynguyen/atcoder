#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n; cin >> n;
    int a1,a2,b1,b2;
    const int oo = 1e9;
    a1  = a2 = b1 = b2 = 0;

    vector<int> a(n + 1), b(n + 1);

    a[0]  = b[0] = oo;
    for (int i=1; i<=n; ++i) 
    {
         cin >> a[i] >> b[i];
        if (a[i]< a[a1]) 
        {
            a2 = a1;
            a1 = i;
        }
        else  if (a[i] < a[a2])
        {
            a2 = i;
        }
        if (b[i] < b[b1]) 
        {
            b2 = b1;
            b1 = i;
        }
        else if (b[i] < b[b2]) 
        {
            b2 = i;
        }
    }
    if (b1 != a1) 
    {
        cout << max(a[a1], b[b1]);
    }
    else 
    {
        cout << min(a[a1] + b[b1], min(max(a[a1], b[b2]) , max(a[a2], b[b1])));
    }
}