#include <bits/stdc++.h>

using namespace std;

bool isGP(int arr[], int s, int r)
{
    //if the array has just one member, then it's already a G.P.
    if (s == 1) return true; //so return true

    //test if the ratio for every pair is always the same
    for (int i = 2; i < s; ++i)
        if (arr[i] / (arr[i - 1]) != r) return false; //if not, return false

    //if nothing's wrong, return true
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[] = {2, 6, 18, 54};
    int s = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + s);
    int r = arr[1] / (arr[0]);

    //Nth member of a G.P.
    //the n variable can be any number, I'll use the array size as example
    cout << arr[0] * (pow(r, s - 1)) << "\n";

    //Sum in range of N
    //n variable can be any range, I'll use the array size as example
    cout << arr[0] * (pow(r, s) - 1) / (r - 1) << "\n";

    //checker whether the given array's terms are a G.P. or not
    (isGP(arr, s, r)) ? cout << "Yes" << "\n" : cout << "No" << "\n"; 

    return 0;
}
