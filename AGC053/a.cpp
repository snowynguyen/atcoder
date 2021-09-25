#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n; string s; cin >> n >> s;
    vector<int> A(n + 1, 0);
    for (auto &i : A) cin >> i;
    vector<int> D(n + 1, 0);
    
    int mi = 0;
    for (int i=0; i<n; ++i) 
    {
        if (s[i] == '<')
            D[i + 1] = D[i] + 1;
        else 
            D[i + 1] = D[i] - 1;
        mi = min(mi, D[i + 1]);
    }

    for (int &i : D) 
        i -= mi - 1;
    
    int st = 1e9;
    for (int i=0; i<=n; ++i) 
    {
        st = min(st, A[i] / D[i]);
        if (i) 
            st = min(st, abs(A[i - 1] - A[i]));
    }

    cout << st << endl;
    for (int z=1; z<st; ++z) 
    {
        for (int i : D)
            cout << i << " ";
        cout << "\n";
    }
    for (int i=0; i<=n; ++i) 
    {
        cout << A[i] - (st - 1) * D[i] << " ";
    }
    cout << endl;
}