#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //array declaration
    int intArr[5] = {
        10,
        2,
        5,
        6,
        22
    };

    int multiDimArr[3][2] = {
        {23, 6},
        {22, 63},
        {63, 12}
    }; //basically multidimensional arrays are
       //arrays containing arrays

    string stringArr[5] = {
        "jOSh",
        "maRIa",
        "ricHard",
        "JoSue",
        "Tanaka"
    };

    bool boolArr[2] = {true, false};

    //array modification
    intArr[3] = 2 + 3;
    stringArr[2] = to_string(intArr[3]);
    (boolArr[1]) ? intArr[4] = intArr[1] + intArr[2] : intArr[4] = intArr[4] - intArr[0];
    intArr[9 / 3] = 2;

    //get size
    int ias = sizeof(intArr) / sizeof(intArr[0]);
    int bas = sizeof(boolArr) / sizeof(boolArr[0]);
    //there's no way to get string size unless iteration

    //sorting
    sort(intArr, intArr + ias);
    sort(boolArr, boolArr + bas);

    reverse(stringArr[0].begin(), stringArr[0].end());

    //transform
    for (int i = 0; i < 5; ++i)
        transform(stringArr[i].begin(), stringArr[i].end(), stringArr[i].begin(), ::tolower);
    transform(stringArr[3].begin(), stringArr[3].end(), stringArr[3].begin(), ::toupper);

    //hashing
    for (int i = 0; i < ias; ++i)
        cout << intArr[i] << "\n";

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
            cout << multiDimArr[i][j] << "\n";
    }

    for (int i = 0; i < 5; ++i)
        cout << stringArr[i] << "\n";

    for (int i = 0; i < bas; ++i)
        cout << boolArr[i] << "\n";

    return 0;
}
