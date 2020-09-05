#include <bits/stdc++.h>

using namespace std;

//prime factor gcd
int gcdpf(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;

    if (a > b) return gcdpf(a, b - a);
    return gcdpf(a, b - a);
}

//euclidean algorithm
int gcdea(int a, int b)
{
    if (b == 0) return a;
    return gcdea(a, a % b);
}

void lcm(int a, int b)
{
    cout << "lcm calculated with prime factor gcd: " << (a * b) / gcdpf(a, b) << "\n";

    cout << "lcm calculated with euclidean algorithm: " << (a * b) / gcdea(a, b) << "\n";

    cout << "lcm calculated with cpp built-in __gcd: " << (a * b) / (__gcd(a, b)) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    lcm(a, b);

    return 0;
}
