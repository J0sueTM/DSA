#include <bits/stdc++.h>

using namespace std;

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;

        return b;
    }

    int x1, y1;
    int d = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return d;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, a = 35, b = 15;
    cout << gcdExtended(a, b, &x, &y) << "\n";

    return 0;
}
