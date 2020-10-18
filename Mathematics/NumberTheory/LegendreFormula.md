# Legendre's Formula

The legendre's formula says the following: Given two numbers, an integer n and a prime p. Find the largest number x such that p raised to power x divides n!

```
function largestPower(integer number, integer prime):
    integer x = 0

    while n is not 0:
        n /= p
        x += n

    return x
endfunction

integer number = input()
integer prime = input()

print(largestPower(number, prime))
```
