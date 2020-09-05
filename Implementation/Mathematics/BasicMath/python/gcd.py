import math

def gcdpf(a, b):
    if a == 0:
        return b
    if b == 0:
        return a
    if a == b:
        return a

    if a > b:
        return gcdpf(a - b, b)
    else:
        return gcdpf(a, b - a)

def gcdea(a, b):
    if b == 0:
        return a

    return gcdea(a, a % b)

a = int(input())
b = int(input())

print(gcdpf(a, b))
print(gcdea(a, b))
print(math.gcd(a, b))
