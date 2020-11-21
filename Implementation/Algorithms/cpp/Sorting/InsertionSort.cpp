#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int s) {
    for (int i = 1; i < s; ++i) {
        int act = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > act) {
            arr[prev + 1] = arr[prev];
            prev -= 1;
        }

        arr[prev + 1] = act;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {12, 11, 13, 5, 6};
    int s = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, s);

    for (int i = 0; i < s; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}
