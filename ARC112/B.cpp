#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long b, c, r; cin >> b >> c;
    if (b == 0) 
    {
        if (c <= 1) 
        {
            r = 0;
        }
        else 
        {
            r = c;
        }
    }
    else if (c == 0)
    {
        r = 1;
    }
    else if (c == 1) 
    {
        r = 2;
    }
    else if (c == 2) 
    {
        r = 3;
    }
    else if (b >0) 
    {
        long long r1 = max(0LL, (c - 1) / 2);
        long long r1_ = max(0LL, (c - 2) / 2);
        r = r1 + r1_;
        long long r2 = max(0LL, min(b, c / 2 + 1));
        long long r2_ = max(0LL, min(b, (c - 1) / 2 + 1));
        r += r2 + r2_;
        r += c >= 2 * b;
    }
    else 
    {
        long long r1 = max(0LL, c / 2 + 1);
        long long r1_ = max(0LL, (c - 1) / 2 + 1);
        r = r1 + r1_;
        long long r2 = max(0LL, min(-b - 1, (c - 1) / 2));
        long long r2_ = max(0LL, min(-b - 1, (c - 2) / 2));
        r += r2 + r2_;
        r += c >= (2 * (-b) + 1);
    }
    cout << r;
}