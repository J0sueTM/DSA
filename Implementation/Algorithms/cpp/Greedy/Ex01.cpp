/*
 *
 * Problem: https://codeforces.com/problemset/problem/34/B 
 *
 * */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, a[10000];
    cin >> m >> n;

    int d = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i];
        if (a[i] < 0)
            d += (a[i]) * -1;
    }
    
    cout << d << "\n";

    return 0;
}
