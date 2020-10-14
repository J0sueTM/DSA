/*
 *
 * Problem: https://codeforces.com/problemset/problem/401/C
 *
 */

import java.util.Scanner;

public class Ex02 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int a, b, c = 0, d = 0;
        a = sc.nextInt();

        while (a > 0) {
            for (int i = 0; i < 3; ++i) {
                b = sc.nextInt();
                c += b;
            }

            if (c > 1) ++d;

            c = 0;
        }

        System.out.println(d);
        --a;
    }
}
