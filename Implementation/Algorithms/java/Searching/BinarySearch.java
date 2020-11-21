import java.util.*;

public class BinarySearch {
    // sorting
    public static void _merge(int arr[], int l, int m, int r) {
        int ls = m - l + 1;
        int rs = r - m;

        int lt[] = new int[ls];
        int rt[] = new int[rs];

        for (int i = 0; i < ls; ++i) {
            lt[i] = arr[l + i];
        }
        for (int i = 0; i < rs; ++i) {
            rt[i] = arr[m + 1 + i];
        }

        int li = 0;
        int ri = 0;
        int mi = l;

        while (li < ls && ri < rs) {
            if (lt[li] <= rt[ri]) {
                arr[mi] = lt[li];
                ++li;
            } else {
                arr[mi] = rt[ri];
                ++ri;
            }
            ++mi;
        }

        while (li < ls) {
            arr[mi] = lt[li];
            ++li;
            ++mi;
        }
        while (ri < rs) {
            arr[mi] = rt[ri];
            ++ri;
            ++mi;
        }
    }

    public static void mergeSort(int arr[], int l, int r) {
        if (l >= r)
            return;

        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        _merge(arr, l, m, r);
    }

    // searching
    public static int recursiveBinarySearch(int arr[], int l, int r, int target) {
        if (l < r) {
            int m = (l + r) / 2;

            if (arr[m] == target)
                return m;
            else if (arr[m] < target)
                return recursiveBinarySearch(arr, m + 1, r, target);
            else
                return recursiveBinarySearch(arr, l, m, target);
        }

        return -1; // not found
    }

    public static int iterativeBinarySearch(int arr[], int l, int r, int target) {
        while (l < r) {
            int m = (l + r) / 2;

            if (arr[m] == target)
                return m;
            else if (arr[m] < target)
                l = m + 1;
            else
                r = m;
        }

        return -1; // not found
    }

    // utility
    public static void printArray(int arr[]) {
        for (int i = 0; i < arr.length; ++i) {
            System.out.println(arr[i]);
        }
    }

    public static void main(String[] args) {
        int arr[] = {10, 50, 30, 70, 80, 60, 20, 90, 40};
        int target = 60;

        //we need to sort the array before use binary search on it
        mergeSort(arr, 0, arr.length - 1);

        System.out.println(recursiveBinarySearch(arr, 0, arr.length, target) + 1);

        target = 20;
        System.out.println(iterativeBinarySearch(arr, 0, arr.length, target) + 1);
    }
}
