## Euclidean algorithm

The euclidean algorithm is a recursive algorithm tha is often used at gcd and lcm algorithms (gcd and lcm is also in this repository, if you want to read about)

The pseudocode:

```
funtion euAlg(integer a, integer b)
    if b is 0
        return b

    return euAlg(a, a % b)
end

integer a
integer b

a = input()
b = input()

write(euAlg())
```
