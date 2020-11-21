import sys

def selectionSort(arr):
    ma = sys.maxsize
    pos = 0

    for i in range(len(arr)):
        for j in range(i, len(arr)):
            if arr[j] < ma:
                ma = arr[j]
                pos = j

        arr[pos], arr[i] = arr[i], arr[pos]
        ma = sys.maxsize

arr = [12, 11, 13, 5, 6]
selectionSort(arr)

for i in arr:
    print(i, end = " ")
