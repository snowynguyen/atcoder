#include <bits/stdc++.h>
using namespace std; 

int main() 
{
    int a, b, c; cin >> a >> b >> c;
    bool ok = 0;
    if (c == 0) 
    {
        if (a > b) 
        {
            ok = 1;
        }
    }
    else 
    {
        ok = a >= b;
    }

    if (ok) cout << "Takahashi";
    else cout << "Aoki";
}