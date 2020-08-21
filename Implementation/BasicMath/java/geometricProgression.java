import java.util.Arrays;
import java.lang.Math;

public class geometricProgression
{
    static boolean isGP(int arr[], int s, int r)
    {
        if (s == 1)
            return true;

        for (int i = 2; i < s; ++i)
            if (arr[i] / (arr[i - 1]) != r)
            {
                return false;
            }

        return true;
    }

    public static void main(String[] args)
    {
        int arr[] = {2, 6, 18, 54};
        int s = arr.length;
        Arrays.sort(arr);
        int r = arr[1] / (arr[0]);

        System.out.println(arr[0] * (Math.pow(r, s - 1)));
        
        System.out.println((arr[0] * (Math.pow(r, s) - 1)) / (r - 1));

        if (isGP(arr, s, r))
        {
            System.out.println("Yes");
        }
        else
        {
            System.out.println("No");
        }
    }
}
