import java.util.*;

public class InsertionSort {
    public static void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; ++i) {
            int act = arr[i];
            int prev = i - 1;

            while (prev >= 0 && arr[prev] > act) {
                arr[prev + 1] = arr[prev];
                prev -= 1;
            }

            arr[prev + 1] = act;
        }
    }

    public static void main(String[] args) {
        int[] arr = {12, 11, 13, 5, 6};

        insertionSort(arr);

        for (int i = 0; i < arr.length; ++i) {
            System.out.println(arr[i]);
        }
    }
}
