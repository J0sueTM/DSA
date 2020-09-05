#include <bits/stdc++.h>

using namespace std;

bool isHP(vector<double> &arr)
{
    if (arr.size() == 1) return true;

    vector<int> rec;
    for (int i = 0; i < arr.size(); ++i)
        rec.push_back((1 / arr[i]));
    sort(rec.begin(), rec.end());
    int d = rec[1] - rec[0];

    for (int i = 2; i < rec.size(); ++i)
        if (rec[i] - rec[i - 1] != d) return false;

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<double> arr = {1 / 5, 1 / 10, 1 / 15, 1 / 20, 1 / 25};
    
    (isHP(arr)) ? cout << "Yes" << "\n" : cout << "No" << "\n";

    return 0;
}
