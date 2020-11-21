#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int s) {
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s - 1; ++j) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[5] = {64, 25, 12, 22, 11};
    int s = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, s);

    for (int i = 0; i < s; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}
