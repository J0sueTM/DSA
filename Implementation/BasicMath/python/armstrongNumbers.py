def isArNum(n, s):
    c = 0
    t = n
    while t > 0:
        r = t % 10
        c += r ** s
        t //= 10

    return (c == n)

n = int(input())
s = len(str(n))
print(isArNum(n, s))
