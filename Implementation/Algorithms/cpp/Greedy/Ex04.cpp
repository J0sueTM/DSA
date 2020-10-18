#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    int c[a];
    for (int i = 0; i < a; ++i) {
        cin >> c[i];
    }
    sort(c, c + a);

    for (int i = 0; i < a; ++i) {
        cout << c[i];
    }

    return 0;
}
