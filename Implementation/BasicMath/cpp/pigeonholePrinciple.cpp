/*
 * This problem was taken from HackerRank
 * www.hackerrank.com
 *
 * Jim is off to a party and is searching for a matching pair of socks. His drawer is filled with socks, each pair of a different color. 
 * In its worst case scenario, how many socks (x) should Jim remove from his drawer until he finds a matching pair?  
 *
 *
 * Input Format
 * The first line contains the number of test cases T.
 * Next T lines contains an integer N which indicates the total pairs of socks present in the drawer.

 * Output Format
 * Print the number of Draws (x) Jim makes in the worst case scenario. 
 *
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while(t--)
    {
        cin >> n;
        cout << ++n << "\n";
    }

    return 0;
}
