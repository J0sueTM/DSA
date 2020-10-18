/*
 *
 * Problem: https://codeforces.com/problemset/problem/34/B
 *
 * */
import java.util.Scanner;

public class Ex01 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m, n;
        int[] a = new int[10000];
        m = sc.nextInt();
        n = sc.nextInt();

        int d = 0;
        for (int i = 0; i < m; ++i) {
            a[i] = sc.nextInt();

            if (a[i] < 0)
                d += (a[i]) * -1;
        }

        System.out.println(d);
    }
}
