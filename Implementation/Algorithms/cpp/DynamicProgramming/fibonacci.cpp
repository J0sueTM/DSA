#include <bits/stdc++.h>

using namespace std;

int n = 8;
int recursivememo[n];
int iterativememo[n];

memset(recursivememo, 0x00, n);
memset(iterativememo, 0x00, n);

recursivememo[0] = 1;
recursivememo[1] = 1;
iterativememo[0] = 1;
iterativememo[1] = 1;

// top-down
int recursiveDynamicProgramming(int pos) {
    if (pos < 2)
        return 1;

    return recursiveDynamicProgramming(pos - 1) + recursiveDynamicProgramming(pos - 2);
}

// bottom-up
int iterativeDynamicProgramming() {
    for (int i = 2; i < n; ++i)
        iterativememo[i] = iterativememo[i - 1] + iterativememo[i - 2];

    return iterativememo[n - 2];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << recursiveDynamicProgramming(n - 1) << "\n";
    // cout << iterativeDynamicProgramming() << "\n";

    return 0;
}
