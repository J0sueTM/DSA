# sorting
def _merge(arr, l, m, r):
    ls = m - l + 1
    rs = r - m

    lt = [0] * ls
    rt = [0] * rs

    for i in range(ls):
        lt[i] = arr[l + i]
    for i in range(rs):
        rt[i] = arr[m + 1 + i]

    li = 0
    ri = 0
    mi = l

    while li < ls and ri < rs:
        if lt[li] <= rt[ri]:
            arr[mi] = lt[li]
            li += 1
        else:
            arr[mi] = rt[ri]
            ri += 1
        mi += 1

    while li < ls:
        arr[mi] = lt[li]
        li += 1
        mi += 1
    while ri < rs:
        arr[mi] = rt[ri]
        ri += 1
        mi += 1

def mergeSort(arr, l, r):
    if l >= r:
        return

    m = (l + (r - 1)) // 2
    mergeSort(arr, l, m)
    mergeSort(arr, m + 1, r)

    _merge(arr, l, m, r)

# searching
def recursiveBinarySearch(arr, l, r, target):
    if l < r:
        m = (l + (r - 1)) // 2
        if arr[m] == target:
            return m
        elif arr[m] < target:
            return recursiveBinarySearch(arr, m, r, target)
        else:
            return recursiveBinarysearch(arr, l, m - 1, target)

    return (-1) # not found

def iterativeBinarySearch(arr, l, r, target):
    while l < r:
        m = (l + (r - 1)) // 2
        if arr[m] == target:
            return m
        elif arr[m] < target:
            l = m + 1
        else:
            r = m - 1

    return -1 # not found

# utilities
def printArray(arr):
    for i in arr:
        print(i, end = " ")
    print("")

arr = [10, 50, 30, 70, 80, 60, 20, 90, 40]
target = 60

# we need to sort the array before we can do binary search on it
mergeSort(arr, 0, len(arr) - 1)

printArray(arr)

print(recursiveBinarySearch(arr, 0, len(arr) - 1, target) + 1)

target = 80
print(iterativeBinarySearch(arr, 0, len(arr) - 1, target) + 1)
