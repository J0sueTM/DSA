/*
 *
 * Problem: https://codeforces.com/problemset/problem/155/A
 *
 */

import java.util.Scanner;

public class Ex03 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n, d, e;
        int[] c = new int[10000];
        
        n = sc.nextInt();
        c[0] = sc.nextInt();

        d = c[0];
        e = c[0];

        int s = 0;
        for (int i = 1; i < n; ++i) {
            c[i] = sc.nextInt();

            if (c[i] > d) {
                d = c[i];
                ++s;
            }

            if (c[i] > e) {
                e = c[i];
                ++s;
            }
        }

        System.out.println(s);

        System.exit(0);
    }
}
