import math

# prime factor
def gcdpf(a, b):
    if a == 0:
        return b
    if b == 0:
        return a
    if a == b:
        return a

    if a > b:
        return gcdpf(a - b, b)

    return gcdpf(a, b - a)

# euclidean algorithm
def gcdea(a, b):
    if b == 0:
        return a

    return gcdea(a, a % b)

def lcm(a, b):
    print("lcm calculated with prime factor gcd: ", ((a * b) / gcdpf(a, b)))

    print("lcm calculated with euclidean algorithm gcd: ", ((a * b) / gcdea(a, b)))

    print("lcm calculated with python built-in gcd: ", math.gcd(a, b))

a = int(input())
b = int(input())

lcm(a, b)
