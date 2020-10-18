n, p = input().split()
n = int(n)
p = int(p)

x = 0
while n:
    n = int(n / p)
    x = x + n

print(x)
