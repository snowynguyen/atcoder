#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin >> t;
    while(t--) 
    {
        long long h;
        int l, r; cin >> l >> r;
        if (l + l > r) 
            cout << 0 << endl;
        else 
        {
            h = (r - l - l) + 1;
            h = (h * (h + 1)) / 2;
            cout << h << endl;   
        }
    }
}