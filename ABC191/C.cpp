#include <bits/stdc++.h>
using namespace std;

int main() 
{
    vector<string> a;
    int m, n;
    cin >> m >> n;
    for(int i=0; i<m; ++i) 
    {
        a.push_back("");
        cin >> a[i];
    }

    int sx=-1, sy;

    for (int i=0; i<m; ++i) 
    for (int j=0; j<n; ++j) 
    {
        if (a[i][j] == '#' ) 
        {
            sx = i; sy = j;
            break;
        }
        if (sx != -1) 
            break;
    }

    int ret = 0;
    int x = sx, y = sy;

    char p = 'X';

    do 
    {
        if (a[x][y] == a[x][y + 1]) 
        {
            ++y;
            if (p != 'D') ++ret;
            p = 'D';
        }
        else if (a[x][y] == a[x+1][y]) 
        {
            ++x;
            if (p != 'R') ++ret;
            p = 'R';
        }
        else break;
    } while (x != sx || y != sy);
    do 
    {
        if (a[x][y] == a[x+1][y]) 
        {
            ++x;
            if (p != 'R') ++ret;
            p = 'R';
        }
        else 
        if (a[x][y] == a[x][y-1]) 
        {
            --y;
            if (p != 'L') ++ret;
            p = 'L';
        }
        else break;
    } while (x != sx || y != sy);
    do 
    {
        if (a[x][y] == a[x][y-1]) 
        {
            --y;
            if (p != 'L') ++ret;
            p = 'L';
        }
        else 
        if (a[x][y] == a[x-1][y]) 
        {
            --x;
            if (p != 'U') ++ret;
            p = 'U';
        }
        else break;
    } while (x != sx || y != sy);
    do 
    {
        if (a[x][y] == a[x-1][y]) 
        {
            --x;
            if (p != 'U') ++ret;
            p = 'U';
        }
        else 
        if (a[x][y] == a[x][y + 1]) 
        {
            ++y;
            if (p != 'R') ++ret;
            p = 'R';
        }
        else break;
    } while (x != sx || y != sy);

    cout << ret;
}