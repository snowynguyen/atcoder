#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n; cin >> n;

    vector<int> f(n+1);
    f[1] = 1;
    f[2] = 3;
    f[3] = 5;
    f[4] = 8;
    for (int i=5; i<=n; ++i) 
    {
        f[i] = f[i - 1];
        for (int j = 1 ; j * j <= i; ++j) 
        {
            if (j *j == i) 
                f[i]++;
            else if (i % j == 0)
                f[i] += 2;
        }
    }

    long long r = 0;
    vector<int> a(n + 1);
    for (int i=1; i<=n; ++i) 
    {
        int l = n / i;
        r += f[l];
    }
    cout << r;
}