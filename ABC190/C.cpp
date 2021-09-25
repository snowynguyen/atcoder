#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[101], b[101];
int c[17], d[17];

int di[101];

int main() 
{
    cin >> n >> m;
    for (int i=1; i<=m; ++i) 
        cin >> a[i] >> b[i];
    cin >> k;
    for( int i=0; i<k; ++i) 
    {
        cin >> c[i] >> d[i];
    }

    int r = 0, cur  =0 , i;

    for (int am = (1 << k) -1; am >=0; --am) 
    {
        for (i=0; i<k; ++i)
        {
            if ((am & (1 << i))) 
            {
                di[c[i]]++;
            }
            else 
            {
                di[d[i]]++;
            }
        }

        cur = 0;
        for (i=1; i<=m; ++i)
        {
            cur += di[a[i]] && di[b[i]];
        }
        r = max(r, cur);

        for (i=0; i<k; ++i)
        {
            if ((am >> i )& 1) 
            {
                di[c[i]]--;
            }
            else 
            {
                di[d[i]]--;
            }
        }
    }
    cout << r;
}