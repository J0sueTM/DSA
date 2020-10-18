import java.util.*;

public class SelectionSort {
    public static void selectionSort(int[] arr) {
        int ma = Integer.MAX_VALUE, pos = 0;
        for (int i = 0; i < arr.length; ++i) {
            for (int j = i; j < arr.length; ++j) {
                if (arr[j] < ma) {
                    ma = arr[j];
                    pos = j;
                }
            }

            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
            ma = Integer.MAX_VALUE;
        }
    }

    public static void main(String[] args) {
        int[] arr = {12, 11, 13, 5, 6};
        
        selectionSort(arr);

        for (int i = 0; i < arr.length; ++i) {
            System.out.println(arr[i]);
        }
    }
}
