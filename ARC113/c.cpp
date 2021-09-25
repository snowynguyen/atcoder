#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s; cin >> s;
    int n = s.size();
    if (n <= 2) 
    {
        cout << 0;
        return 0;
    }
    int last = '.';
    s = " " + s;
    vector<int> C(129, 0);
    vector<long long> f(n + 2, 0);
    char pr = '.';
    for (int i=n; i>=3; --i) 
    {
        C[s[i]] ++;
        f[i] = f[i + 1];
        if (s[i-2] == s[i-1] && s[i-1] != s[i]) 
        {
            if (pr != s[i-2]) 
            {
                pr = s[i-2];
                f[i] += n - i + 1 - C[s[i - 2]];
                for (int j='a'; j<='z'; ++j) 
                {
                    if (j == pr) continue;
                    C[pr] += C[j];
                    C[j] = 0;
                }
            }
            else 
            {
                f[i] += last - i - 2;
            }
            last = i;
        }
    } 
    cout << f[3];
}