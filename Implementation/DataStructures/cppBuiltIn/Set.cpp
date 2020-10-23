#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
     * Set is a data structure that holds a collections of elements
     * Sets just hold one element per collection
     * We can have insert 200 "hello", but we'll have just one "hello"
     * 
     * There are two types of sets in cpp:
     * set is a balanced binary tree that works in O(log n)
     * unordered_set is a hashed array that works in O(1)
     */

    // declaration
    set<int> fSet;
    unordered_set<int> sSet;

    //manipulation
    for (int i = 0; i < 10; ++i)
        fSet.insert(10);

    cout << fSet.count(10) << "\n"; // will output 1, we've inserted 10 10 times, but there just one element per collection

    return 0;
}
