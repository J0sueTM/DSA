# Problem: https://codeforces.com/problemset/problem/34/B 

m, n = input().split()
a = [int(i) for i in input().split()]

d = 0
for i in a:
    if a[i] < 0:
        d += (a[i]) * -1

print(d)
