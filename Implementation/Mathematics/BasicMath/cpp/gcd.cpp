#include <bits/stdc++.h>

using namespace std;

int gcdpf(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;

    if (a > b)
        return gcdpf(a - b, b);

    return gcdpf(a, b - a);
}

int gcdea(int a, int b)
{
    if (b == 0)
        return a;

    return gcdea(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a = 12, b = 24;

    //prime factor algorithm
    cout << gcdpf(a, b) << "\n";

    //euclidean algorithm
    cout << gcdea(a, b) << "\n";

    //cpp buit-in gcd function
    cout << __gcd(a, b) << "\n";

    return 0;
}
