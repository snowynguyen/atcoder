#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n; cin >> n;
    vector<vector<int > > D(n + 1, vector<int> ());
    for (int i=1; i<=n; ++i) 
    {
        for (int j = i + i; j<=n; j += i) 
        {
            D[j].push_back(i);
        }
    }
    vector<int> f(n + 1, 0);
    f[1] = 1;
    vector<int> tmp (500, 0);
    for (int i=2; i<=n; ++i) 
    {
        for (int j : D[i])
        {
            tmp[f[j]]++;
        }
        for (int k = 1; ; ++k) 
        {
            if (tmp[k] == 0) 
            {
                f[i] = k;
                break;
            }
        }
        for (int j : D[i]) 
        {
            tmp[f[j]]--;
        }
    }
    for (int i=1; i<=n; ++i) 
        cout << f[i] << " ";
}