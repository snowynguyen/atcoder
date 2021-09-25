#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n; cin >> n;
    vector<string> a(n);
    for (auto &s : a) cin >> s;
    int b00 = 0, w00 = 0;
    for (int i=0; i<n; ++i) 
    {
        for (int j=0; j<n; ++j)
        {
            if ((i+j ) % 2 == 0) 
            {
                b00 += a[i][j] == 'B';
                w00 += a[i][j] == 'W';
            }
            else 
            {
                b00 += a[i][j] == 'W';
                w00 += a[i][j] == 'B';
            }        
        }
    }
    int ret = 0;
    for (int i=0; i<n; ++i) 
    {
        for (int j=0; j<n; ++j) 
        {
            if (a[i][j] == '?') 
            {
                if ((i + j) % 2 == 0) 
                    a[i][j] = b00 > w00 ? 'B': 'W';
                else 
                    a[i][j] = b00 > w00 ? 'W': 'B';
            }
            if (i > 0) 
                ret += a[i][j] != a[i-1][j];
            if (j > 0) 
                ret += a[i][j] != a[i][j-1];
        }
    }
    cout << ret;
}