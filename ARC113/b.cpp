#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int a, b, c; cin >> a >> b >> c;
    b %=4 ;
    a %= 10;
    if (b == 3) 
     b = -1;
    if (b == 2) 
    {
        if (c > 1) 
        {
            cout << a * a * a * a % 10;
        }
        else 
        {
            cout << a * a % 10;
        }
    }
    else if (b == 0) 
    {
        cout << a * a * a * a % 10;
    }
    else 
    {
        if (c % 2 == 0) 
        {
            b = b * b;
        }
        if (b == -1) 
        {
            cout << a * a *a % 10;
        }
        else 
        {
            cout << a;
        }
    }
}