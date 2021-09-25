#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s; cin >> s;
    bool h = 1;
    for (int i=0; i <s.size(); ++i)
    {
        if (i % 2  == 0) 
        {
            h &= 'a' <= s[i] && s[i] <= 'z';
        }
        else 
        {
            h &= 'A' <= s[i] && s[i] <= 'Z';
        }
    }
    if (h) 
        cout << "Yes";
    else 
        cout << "No";
}