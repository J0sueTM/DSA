# Problem: https://codeforces.com/problemset/problem/34/B

m, n = input().split()
arr = [int(i) for i in input().split()]

d = 0
c = 0
for i in arr:
    if c >= int(n):
        break

    if i < 0:
        d += i * -1
        c += 1

print(d)
