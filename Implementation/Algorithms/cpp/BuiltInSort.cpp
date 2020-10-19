#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int s) {
    for (int i = 0; i < s; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    //built in sort function
    // sort(a, b);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {12, 11, 13, 5, 6, 7};
    int s = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec = {12, 11, 13, 5, 6, 7};

    // example with array
    cout << "Usorted array: \n";
    printArray(arr, s);
    sort(arr, arr + s);
    cout << "Sorted array: \n";
    printArray(arr, s);


    // example with vector
    cout << "Unsorted vector: \n";
    printVector(vec);
    sort(vec.begin(), vec.end());
    cout << "Sorted vector: \n";
    printVector(vec);

    return 0;
}
