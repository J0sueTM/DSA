#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* utilities */
void merge(int arr[], int left, int middle, int right) {
    int lSize = middle - left + 1;
    int rSize = right - middle;

    int lTemp[lSize];
    int rTemp[rSize];

    for (int i = 0; i < lSize; ++i)
        lTemp[i] = arr[left + i];

    for (int i = 0; i < rSize; ++i)
        rTemp[i] = arr[middle + 1 + i];

    int lIndex = 0;
    int rIndex = 0;
    int mIndex = left;

    while (lIndex < lSize && rIndex < rSize) {
        if (lTemp[lIndex] <= rTemp[rIndex]) {
            arr[mIndex] = lTemp[lIndex];
            ++lIndex;
        } else {
            arr[mIndex] = rTemp[rIndex];
            ++rIndex;
        }

        ++mIndex;
    }

    while (lIndex < lSize) {
        arr[mIndex] = lTemp[lIndex];
        ++lIndex;
        ++mIndex;
    }

    while (rIndex < rSize) {
        arr[mIndex] = rTemp[rIndex];
        ++rIndex;
        ++mIndex;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int middle = (left + right) / 2;
    merge_sort(arr, left, middle);
    merge_sort(arr, middle + 1, right);

    merge(arr, left, middle, right);
}

bool isAP(int arr[], int s, int d) {
    if (s == 1)
        return true;

    for (int i = 2; i < s; ++i) {
        if (arr[i] - arr[i - 1] != d)
            return false;
    }

    return true;
}

int main() {
    int arr[] = {20, 15, 5, 0, 10};
    int s = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, s - 1);
    int d = arr[1] - arr[0];

    printf("%i \n", arr[0] + (s - 1) * d);

    printf("%i \n", (s / 2) * (arr[0] + (s - 1) * d));

    if (isAP(arr, s, d))
        printf("Yes \n");
    else
        printf("No \n");

    return 0;
}
