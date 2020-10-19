import java.util.*;

public class MergeSort {
    public static void _merge(int[] arr, int leftSide, int middleSide, int rightSide) {
        int leftSize = (middleSide - leftSide) + 1;
        int rightSize = rightSide - middleSide;

        int[] leftTemp = new int[leftSize];
        int[] rightTemp = new int[rightSize];

        for (int i = 0; i < leftSize; ++i) {
            leftTemp[i] = arr[leftSide + i];
        }
        for (int i = 0; i < rightSize; ++i) {
            rightTemp[i] = arr[middleSide + 1 + i];
        }

        int leftIndex = 0;
        int rightIndex = 0;
        int mergeIndex = leftSide;

        while (leftIndex < leftSize && rightIndex < rightSize) {
            if (leftTemp[leftIndex] <= rightTemp[rightIndex]) {
                arr[mergeIndex] = leftTemp[leftIndex];
                ++leftIndex;
            } else {
                arr[mergeIndex] = rightTemp[rightIndex];
                ++rightIndex;
            }
            ++mergeIndex;
        }

        while (leftIndex < leftSize) {
            arr[mergeIndex] = leftTemp[leftIndex];
            ++leftIndex;
            ++mergeIndex;
        }
        while (rightIndex < rightSize) {
            arr[mergeIndex] = rightTemp[rightIndex];
            ++rightIndex;
            ++mergeIndex;
        }
    }

    public static void mergeSort(int[] arr, int leftSide, int rightSide) {
        if (leftSide >= rightSide)
            return;

        int middleSide = (leftSide + rightSide) / 2;

        mergeSort(arr, leftSide, middleSide);
        mergeSort(arr, middleSide + 1, rightSide);

        _merge(arr, leftSide, middleSide, rightSide);
    }

    public static void main(String[] args) {
        int[] arr = {12, 11, 13, 5, 6, 7};
        int s = arr.length;
        
        mergeSort(arr, 0, s - 1);

        for (int i = 0; i < s; ++i) {
            System.out.println(arr[i]);
        }
    }
}
