def isGP(arr, s, r):
    if s == 1:
        return True

    for i in range(2, s):
        if (arr[i] / (arr[i - 1]) != r):
            return False

    return True

arr = [2, 6, 18, 54];
s = len(arr)
arr.sort()
r = arr[1] / (arr[0])

print(arr[0] * (r**(s - 1)))

print((arr[0] * (r**(s) - 1)) / (r - 1))

if isGP(arr, s, r):
    print("Yes")
else:
    print("No")
