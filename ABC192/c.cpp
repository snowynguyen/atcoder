#include <bits/stdc++.h>
using namespace std;

int up(int x) 
{
    stringstream ss;
    ss << x << ' ';
    string s;  ss >> s;
    sort (s.begin(), s.end(), greater<char>());
    ss << s << ' ';
    int y;
    ss >> y;
    return y;
}

int lo(int x) 
{
    stringstream ss;
    ss << x << ' ';
    string s;  ss >> s;
    sort (s.begin(), s.end());
    ss << s << ' ';
    int y; 
    ss >> y;
    return y;
}

int main()
{
    int n, k; cin >> n >> k;
    for (int i=1; i<=k; ++i) 
    {
        n = up(n) - lo(n);
    }
    cout << n;
}