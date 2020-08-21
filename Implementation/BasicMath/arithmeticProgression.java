import java.util.Arrays;

public class arithmeticProgression
{
    static boolean isAP(int arr[], int s, int d)
    {
        if (s == 1)
            return true;

        for (int i = 2; i < s; ++i)
            if (arr[i] - arr[i - 1] != d)
                return false;

        return true;
    }

    public static void main(String[] args)
    {
        int arr[] = {20, 15, 5, 0, 10};
        int s = arr.length;
        Arrays.sort(arr);
        int d = arr[1] - arr[0];

        System.out.println(arr[0] + (s - 1) * d);

        System.out.println((s - 1) * (arr[0] + (s - 1) * d));

        if (isAP(arr, s, d))
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No");
        }
    }
}
