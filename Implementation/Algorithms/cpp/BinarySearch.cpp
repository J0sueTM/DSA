#include <bits/stdc++.h>

using namespace std;

// sorting
void _merge(int arr[], int l, int m, int r) {
    int ls = m - l + 1;
    int rs = r - m;

    int lt[ls];
    int rt[rs];

    for (int i = 0; i < ls; ++i) {
        lt[i] = arr[l + i];
    }
    for (int i = 0; i < rs; ++i) {
        rt[i] = arr[m + 1 + i];
    }

    int li = 0;
    int ri = 0;
    int mi = l;

    while (li < ls && ri < rs) {
        if (lt[li] <= rt[ri]) {
            arr[mi] = lt[li];
            ++li;
        } else {
            arr[mi] = rt[ri];
            ++ri;
        }
        ++mi;
    }

    while (li < ls) {
        arr[mi] = lt[li];
        ++li;
        ++mi;
    }
    while (ri < rs) {
        arr[mi] = rt[ri];
        ++ri;
        ++mi;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r)
        return;

    int m = (l + r) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    _merge(arr, l, m, r);
}

// binary search
int recursiveBinarySearch(int arr[], int l, int r, int target) {
    if (l < r) {
        int m = (l + r) / 2;

        if (arr[m] == target)
            return m;
        else if (arr[m] > target)
            return recursiveBinarySearch(arr, l, m, target);
        else if (arr[m] < target)
            return recursiveBinarySearch(arr, m + 1, r, target);
    }

    return -1; // not found
}

int iterativeBinarySearch(int arr[], int l, int r, int target) {
    while (l <= r) {
        int m = (l + r) / 2;

        if (arr[m] == target)
            return m;
        else if (arr[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1; // not found
}
 
// utility
void printArray(int arr[], int s) {
    for (int i = 0; i < s; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {10, 50, 30, 70, 80, 60, 20, 90, 40};
    int s = sizeof(arr) / sizeof(arr[0]);
    int target = 60;
    
    // we need to sort the arry before we can binary search on it
    mergeSort(arr, 0, s - 1);

    cout << "Recursive Binary Search: \n";
    cout << recursiveBinarySearch(arr, 0, s, target) + 1 << "\n";

    target = 20;
    cout << "Iterative Binary Search: \n";
    cout << iterativeBinarySearch(arr, 0, s - 1, target) + 1 << "\n";

    return 0;
}
