def isHP(arr):
    if len(arr) == 1:
        return True

    rec = []
    for i in range(len(arr)):
        rec.append((1 / (arr[i])))
    rec.sort()
    d = rec[1] - rec[0]

    for i in range(2, len(rec)):
        if (rec[i] - rec[i - 1] != d):
            return False

    return True

arr = [1 / 5, 1 / 10, 1 / 15, 1 / 20, 1 / 25]

if (isHP(arr)):
    print("Yes")
else:
    print("Yes")
