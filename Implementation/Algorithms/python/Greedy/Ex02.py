 # Problem: https://codeforces.com/problemset/problem/401/C

a = input().split()
c = 0
d = 0

while a > 0:
    b = [int(i) for i in input().split()]
    for i in b:
        c += b[i]


    if c > 1:
        d += 1

    a -= 1

print(d)
