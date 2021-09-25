#include <bits/stdc++.h> 
using namespace std;

int main() 
{
    int n; cin >> n;
    vector<long long> X(n);
    for (auto &x : X)    
        cin >> x;
    long long r = 1e18;
    vector<int> S = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    for (int mask = (1 << (S.size()) - 1); mask >=0 ; --mask) 
    {
        long long cur = 1;
        for (int i=0 ; i < S.size(); ++i) 
        {
            if (mask & (1 << i)) 
            {
                cur *= S[i];
            }
        }
        bool good = 1;
        for (auto x : X) 
            good &= __gcd(x, cur) > 1LL;
        if (good)
            r = min(r, cur);
    }
    cout << r;
}