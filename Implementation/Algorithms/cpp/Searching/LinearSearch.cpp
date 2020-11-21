#include <bits/stdc++.h>

using namespace std;

int linearSearch(int arr[], int s, int target) {
    for (int i = 0; i < s; ++i) {
        if (arr[i] == target)
            return i;
    }

    return -1; // not found
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {10, 50, 30, 70, 80, 60, 20, 90, 40};
    int s = sizeof(arr) / sizeof(arr[0]);

    cout << linearSearch(arr, s, 60) << "\n";

    return 0;
}