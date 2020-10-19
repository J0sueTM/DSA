def mergeSort(arr):
    if len(arr) <= 1:
        return

    middle = len(arr)//2
    leftTemp = arr[:middle]
    rightTemp = arr[middle:]

    mergeSort(leftTemp)
    mergeSort(rightTemp)

    leftIndex = rightIndex = mergeIndex = 0
    while leftIndex < len(leftTemp) and rightIndex < len(rightTemp):
        if leftTemp[leftIndex] <= rightTemp[rightIndex]:
            arr[mergeIndex] = leftTemp[leftIndex]
            leftIndex += 1
        else:
            arr[mergeIndex] = rightTemp[rightIndex]
            rightIndex += 1
        mergeIndex += 1

    while leftIndex < len(leftTemp):
        arr[mergeIndex] = leftTemp[leftIndex]
        leftIndex += 1
        mergeIndex += 1
    while rightIndex < len(rightTemp):
        arr[mergeIndex] = rightTemp[rightIndex]
        rightIndex += 1
        mergeIndex += 1


arr = [12, 11, 13, 5, 6, 7]
mergeSort(arr)

for i in arr:
    print(i, end = " ")
