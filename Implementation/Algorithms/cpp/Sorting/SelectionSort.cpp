#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int s) {
    int ma = INT_MAX, pos = 0;
    
    for (int i = 0; i < s; ++i) {
        for (int j = i; j < s; ++j) {
            if (arr[j] < ma) {
                ma = arr[j];
                pos = j;
            }
        }

        swap(arr[i], arr[pos]);
        ma = INT_MAX;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[5] = {12, 11, 13, 5, 6};
    int s = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, s);

    for (int i = 0; i < s; ++i) {
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}
