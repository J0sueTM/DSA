#include <bits/stdc++.h>

using namespace std;

bool isFS(int arr[], int s)
{
    if (s == 1) return true;

    for (int i = 2; i < s; ++i)
        if (arr[i] - arr[i - 1] != arr[i - 2]) return false;

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[10];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < 10; ++i)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    int s = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + s);

    (isFS(arr, s)) ? cout << "Yes \n" : cout << "No \n"; 

    return 0;
}
