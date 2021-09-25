#include <bits/stdc++.h>
using namespace std;

const int N = 502;
int a[N][N];
long long sum;

int main() 
{
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    long long sum = 0;
    for (int i=1; i<=n; ++i) 
    {
        for (int j=1; j<=n; ++j) 
        {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    if (sum % n) 
    {
        return cout << "No", 0;
    }
    sum /= n;


}