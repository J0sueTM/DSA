#include <bits/stdc++.h>

using namespace std;

bool isPS(int arr[], int s)
{
    if (s == 1) return true;

    for (int i = 3; i < s; ++i)
        if (arr[i] - arr[i - 2] != arr[i - 3]) return false;

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;
    for (int i = 3; i < 10; ++i)
        arr[i] = arr[i - 2] + arr[i - 3];
    sort(arr, arr + 10);
    int s = sizeof(arr) / sizeof(arr[0]);

    (isPS(arr, s)) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
