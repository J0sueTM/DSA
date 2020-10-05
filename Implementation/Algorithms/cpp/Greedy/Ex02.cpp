/*
 *
 * Problem: https://codeforces.com/problemset/problem/401/C
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c = 0, d = 0;
    cin >> a;

    while (a--)
    {
        for (int i = 0; i < 3; ++i)
        {
            cin >> b;
            c += b;
        }

        if (c > 1) ++d;

        c = 0;
    }

    cout << d << "\n";
    
    return 0;
}
