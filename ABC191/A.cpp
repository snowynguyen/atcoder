#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int v, s, t, d;
    cin >> v >> s >> t >> d;
    if (v * s <= d && d <= v * t) 
    {
        cout << "No";
    }
    else 
    {
        cout << "Yes";
    }
}