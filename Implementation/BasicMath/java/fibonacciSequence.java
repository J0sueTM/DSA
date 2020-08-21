public class fibonacciSequence
{
    static boolean isFS(int arr[])
    {
        if (arr.length == 1)
            return true;

        for (int i = 2; i < arr.length; ++i)
            if (arr[i] - arr[i - 1] != arr[i - 2])
                return false;

        return true;
    }

    public static void main(String[] args)
    {
        int[] arr = new int[10];
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i < arr.length; ++i)
            arr[i] = arr[i - 1] + arr[i - 2];

        if (isFS(arr))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
