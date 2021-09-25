#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int k; 
    string a, b;
    cin >> k >> a >> b;
    for (int i=0; i<4; ++i) {
        a[i] -= '0';
        b[i] -= '0';
    }
    int total = 0;
    int win = 0;
    for (int i=1; i<=9; ++i) 
    for (int j=1; j<=9; ++j) 
    {
        a[4] = i;
        b[4] = j;
        bool fail = 0;
        long long A =0, B = 0;
        for (int d=1; d<=9; ++d) 
        {
            int cnt = 0;
            long long ka = 1, kb = 1;
            for (int z=0; z<5; ++z) 
            {
                if (a[z] == d) ka *= 10;
                if (b[z] == d) kb *= 10;
                cnt += (a[z] == d) + (b[z] == d);
            }
            A += d * ka;
            B += d * kb;
            if (cnt > k) 
                fail = true;
        }
        if (!fail) 
        {
            total++;
            win += A > B;
        }
    }
    cout << fixed << setprecision(12) << (long double) win / total ;
}