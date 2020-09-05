def isPS(arr, s):
    if s == 1:
        return True

    for i in range(3, s):
        if (arr[i] - arr[i - 2] != arr[i - 3]):
            return False

    return True

arr = [1, 1, 1, 0, 0, 0, 0, 0, 0, 0]
s = len(arr)
for i in range(3, s):
    arr[i] = arr[i - 2] + arr[i - 3]

if (isPS(arr, s)):
    print("Yes")
else:
    print("No")
