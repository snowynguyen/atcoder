#include <bits/stdc++.h>
using namespace std;

int main ()
{
    #define ld long double

    int n; cin >> n;
    ld a = 1;
    for (int i=n - 1; i >= 1; -- i) 
    {
        a = a * n / i;
    }
    cout << fixed << setprecision(16) << a;
}