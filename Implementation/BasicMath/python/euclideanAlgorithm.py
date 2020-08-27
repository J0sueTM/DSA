def euAlg(a, b):
    if b == 0:
        return a

    return euAlg(a, a % b)

a = int(input())
b = int(input())

print(euAlg(a, b))
