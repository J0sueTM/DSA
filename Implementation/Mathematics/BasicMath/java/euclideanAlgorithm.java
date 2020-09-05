import java.util.Scanner;

public class euclideanAlgorithm
{
    public static int euAlg(int a, int b)
    {
        if (b == 0)
            return a;

        return euAlg(a, a % b);
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int a, b;

        a = sc.nextInt();
        b = sc.nextInt();

        System.out.println(euAlg(a, b));
    }
}
