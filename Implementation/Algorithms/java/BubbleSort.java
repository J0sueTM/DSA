import java.util.*;

public class BubbleSort {
    public static void bubbleSort(int[] arr) {
        for (int i = 0; i < arr.length; ++i) {
            for (int j = 0; j < arr.length - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;

                    //We also can use
                    //Collections.swap(Arrays.asList(arr), j, j + 1);
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {64, 25, 12, 22, 11};

        bubbleSort(arr);

        for (int i = 0; i < arr.length; ++i)
            System.out.println(arr[i]);
    }
}
