def isAP(arr, s, d):
    if (s == 1):
        return True

    for i in range(2, s):
        if (arr[i] - arr[i - 1] != d):
            return False 

    return True
        

arr = [20, 15, 5, 0, 10]
s = len(arr)
arr.sort()
d = arr[1] - arr[0]

print(arr[0] + (s - 1) * d)

print((s / 2) * (arr[0] + (s - 1) * d))

print("Yes") if (isAP(arr, s, d)) else print("No")
