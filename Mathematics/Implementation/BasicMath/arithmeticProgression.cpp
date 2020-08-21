#include <bits/stdc++.h>

using namespace std;

bool isAP(int arr[], int s, int d)
{
    //if the array just contains one meber, so it's already an A.P.
    if (s == 1) return true;

    //check for every pair if their difference is the same
    for (int i = 2; i < s; ++i)
        if (arr[i] - arr[i - 1] != d) return false; //if not, return false

    //nothing wrong, return true
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {20, 15, 5, 0, 10};
    int s = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + s);
    int d = arr[1] - arr[0];

    //formula of Nth term of an A.P.
    //we can use any n variable, I'll use the last position, the size of the array
    cout << arr[1] + (s - 1) * d << "\n";

    //formula of forst Nth terms of an A.P.
    //we can use any n variable, I'll use the size of the array
    cout << (s / 2) * (arr[0] + (s - 1) * d) << "\n";

    //verify whether given array is an A.P. or not
    (isAP(arr, s, d)) ? cout << "Yes" << "\n" : cout << "No" << "\n"; 

    return 0;
}
