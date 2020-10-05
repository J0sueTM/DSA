/*
 *
 * Problem: https://codeforces.com/problemset/problem/155/A
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c[10000], d, e;
    cin >> n >> c[0];

    d = e = c[0];
    int s = 0;
    for (int i = 1; i < n; ++i) {
        cin >> c[i];

        if (c[i] < d) {
            d = c[i];
            ++s;
        }

        if (c[i] > e) {
            e = c[i];
            ++s;
        }
    }

    cout << s << "\n";

    return 0;
}
