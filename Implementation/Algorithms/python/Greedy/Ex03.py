n, d = input().split()
e = d
c = [int(i) for i in input().split()]
c[0] = d

s = 0
for i in range(n):
    if c[i] < d:
        d = c[i]
        s += 1

    if c[i] > e:
        e = c[i]
        s += 1

print(s)
