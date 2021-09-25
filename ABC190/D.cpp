#include <bits/stdc++.h>
using namespace std;

bool gg(long long s, long long d) 
{
    long long  b = (s + d - 1) / 2;
    long long a =(s-d + 1) / 2;
    return (a + b == s) && (b -a + 1 == d);
}

int main() 
{
    long long n; cin >> n;
    n += n;
    int r = 0;
    for (long long i = 1; i * i <= n; ++i) 
    {
        if (n % i == 0) 
        {
            r += gg(i, n / i);
            if (i * i < n) 
                r += gg(n/i, i);
        }
    }
    cout << r;
}