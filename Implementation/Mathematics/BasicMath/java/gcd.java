import java.util.Scanner;

public class gcd
{
    public static int gcdpf(int a, int b)
    {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        if (a == b)
            return a;

        if (a > b)
            return gcdpf(a, a - b);

        return gcdpf(a, b - a);
    }

    public static int gcdea(int a, int b)
    {
        if (b == 0)
            return a;

        return gcdea(a, a % b);
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();

        System.out.println(gcdpf(a, b));
        System.out.println(gcdea(a, b));

    }
}
