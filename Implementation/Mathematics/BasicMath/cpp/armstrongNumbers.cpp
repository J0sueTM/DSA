#include <bits/stdc++.h>

using namespace std;

int size(int n)
{
    int c = 0;
    while (n)
    {
        ++c;
        n /= 10;
    }

    return c;
}

bool isArNum(int n)
{
    int s = size(n);
    int t = n, c = 0, r;
    while (t)
    {
        r = t % 10;
        c += pow(r, s);
        t /= 10;
    } 

    return (n == c);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    (isArNum(n)) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
