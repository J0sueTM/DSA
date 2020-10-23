#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
     * A dynamic array is an array that can change it's size
     * In c++, the most popular implementation of the dynamic
     * array is the vector
     */

    // declaration
    vector<int> fVector;
    vector<string> sVector = {"josh", "maria"};
    vector<float> tVector(10, 4.4f);

    // manipulation
    fVector.push_back(5);
    fVector.push_back(8);
    fVector.push_back(10);
    fVector.pop_back();

    // hashing
    for (int i = 0; i < fVector.size(); ++i)
        cout << fVector[i] << " ";
    cout << "\n";    

    for (auto x : sVector)
        cout << x << " ";
    cout << "\n";

    for (int i = 0; i < tVector.size(); ++i)
        cout << tVector[i] << " ";
    cout << "\n";

    cout << fVector.back() << "\n"; // return the last inserted element in vector

    return 0;
}
