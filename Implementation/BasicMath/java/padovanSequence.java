import java.util.Arrays;

public class padovanSequence
{
    public static boolean isPS(int arr[], int s)
    {
        if (s == 1)
            return true;

        for (int i = 3; i < s; ++i)
            if (arr[i] - arr[i - 2] != arr[i - 3])
                return false;
        
        return true;
    }

    public static void main(String[] args)
    {
        int[] arr = new int[10];
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 1;
        int s = arr.length;
        Arrays.sort(arr);
        for (int i = 3; i < s; ++i)
            arr[i] = arr[i - 2] + arr[i - 3];

        if (isPS(arr, s))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
