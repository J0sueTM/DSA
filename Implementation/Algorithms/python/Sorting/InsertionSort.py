def insertionSort(arr):
    for i in range(1, len(arr)):
        act = arr[i]
        prev = i - 1

        while prev >= 0 and arr[prev] > act:
            arr[prev + 1] = arr[prev]
            prev -= 1

        arr[prev + 1] = act

arr = [12, 11, 13, 5, 6]
insertionSort(arr)

for i in arr:
    print(i)
