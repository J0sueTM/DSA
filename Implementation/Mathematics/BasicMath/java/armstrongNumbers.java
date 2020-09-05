import java.util.Scanner;
import java.lang.Math;

public class armstrongNumbers
{
    public static int size(int n)
    {
        int c = 0, t = n;
        while (t != 0)
        {
            ++c;
            t /= 10;
        }

        return c;
    }

    public static boolean isArNum(int n)
    {
        int t = n, c = 0, r;
        int s = size(n);

        while (t != 0)
        {
            r = t % 10;
            c += Math.pow(r, s);
            t /= 10;
        }

        return (n == c);
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        if (isArNum(n))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
