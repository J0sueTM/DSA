#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    int x = 0;
    while (n) {
        n /= p;
        x += n;
    }

    cout << x << "\n";

    return 0;
}
