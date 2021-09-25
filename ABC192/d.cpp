#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string x;
    long long m;
    cin >> x >> m;
    if (x == "1") 
    {
        cout << 1;
        return 0;
    }
    if (x.size() == 1) 
    {
        int X = x[0] - '0';
        if (X <= m) 
        {
            cout << 1;
        }
        else 
        {
            cout << 0;
        }
        return 0;
    }
    if (x.size() == 2) 
    {
        cout << max(0LL, (m - (x[0] - '0')) / (x[1] - '0'));
        return 0;
    }
}