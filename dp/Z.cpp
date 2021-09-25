#include <bits/stdc++.h>
using namespace std;

#define lint long long
#define pii pair<int, int> 
#define ld long double
#define TASK ""

const int N = 200002;

struct TLine 
{
    int a;
    lint b;

    TLine (int a, lint b) : a(a), b(b) {}

    ld intersect(TLine d) 
    {
        return (ld)(d.b - b) / (a - d.a);
    }

    lint at (lint x) 
    {
        return a*x + b;
    }
};

int n; 
lint c;
int h[N];
lint f[N];

void driver()
{
    cin >> n >> c;
    for (int i=1; i<=n; ++i) 
    {
        cin >> h[i];
    }

    vector<TLine> s;
    f[1] = 0;
    
    s.push_back(TLine(-2 * h[1], f[1] + c + (lint) h[1] * h[1]));

    TLine l(0, 0);

    for (int i=2, j = 0; i<=n; ++i) 
    {
        f[i] = s[j].at(h[i]) + (lint)h[i] * h[i];

        l = TLine(-2 * h[i], f[i] + c + (lint)h[i] * h[i]);
        while (s.size() >= 2 && ((s[s.size() - 2].intersect(l)) > s.back().intersect(l) ))
        {
            s.pop_back();
        }
        if (s.size() <= j) 
            j = s.size() - 1;
        s.push_back(l);
        while (j < s.size() - 1 && s[j].intersect(s[j + 1]) < h[i + 1]) 
            ++j;
    }

    cout << f[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    driver();
}
