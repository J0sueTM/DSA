def isFS(arr):
    if len(arr) == 1:
        return True

    for i in range(2, len(arr)):
        if (arr[i] - arr[i - 1] != arr[i - 2]):
            return False

    return True

arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
arr[0] = 1
arr[1] = 1
for i in range(2, len(arr)):
    arr[i] = arr[i - 1] + arr[i - 2]
arr.sort()

if (isFS(arr)):
    print("Yes")
else:
    print("No")
