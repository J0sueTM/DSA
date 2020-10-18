import java.util.Scanner;

public class LegendreFormula {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int p = sc.nextInt();

        int x = 0;
        while (n > 0) {
            n /= p;
            x += n;
        }

        System.out.println(x);
    }
}
