#include <bits/stdc++.h>

using namespace std;

int eugcd(int a, int b)
{
    if (b == 0) return a;

    return eugcd(a, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    cout << eugcd(a, b) << "\n";

    return 0;
}
