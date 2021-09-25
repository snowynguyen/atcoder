#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y; cin >> n >> x >> y;
    for (int i=1; i<=n; ++i) 
    {
        int u, v; cin >> u >> v;
        if (u < x && v > y) 
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}