import java.util.*;

public class LinearSearch {
    public static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] == target)
                return i;
        }

        return -1; // not found
    }

    public static void main(String[] args) {
        int arr[] = {10, 50, 30, 70, 80, 60, 20, 90, 40};
        int target = 60;

        System.out.println(linearSearch(arr, target));
    }
}
