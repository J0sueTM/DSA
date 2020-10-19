import java.util.*;

public class BuiltInSort {
    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; ++i) {
            System.out.println(arr[i]);
        }
    }

    public static void main(String[] args) {
        // built in function for sorting
        // Arrays.sort(a);

        int[] arr = {12, 11, 13, 5, 6, 7};

        System.out.println("Usorted array: ");
        printArray(arr);
        Arrays.sort(arr);
        System.out.println("Sorted array: ");
        printArray(arr);
    }
}
