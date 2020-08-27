# Greatest common divisor

In mathematics, the gratest common divisor (gcd) of two or more integers, which are not all zero, its the largest positive integer that divides each of the integers.

**Example**

![](https://quicklatex.com/cache3/d2/ql_68cde54e1e673c48b54e317ca6b5d9d2_l3.png)

### Formula

There are 2 ways to find the gcd of two numbers:

- prime factors
- Euclidean

###### There is also the **__gcd** function in c++ STL

**prime factors algorithm**

```
function gcd(integer a, integer b)
    
    if a is 0
        return b
    else if b is 0
        return a

    if a is b
        return a

    if a is greater than b
        return gcd(a - b, b)

    return gcd(a, b - a)
end

integer a
integer b

input a
input b

write(gcd(a, b))
```

**euclidean algorithm**

```
function gcd(integer a, integer b)
    if b is 0
        return a

    return gcd(b, a % b)
end

integer a
integer b

input a
input b

write(gcd(a, b))
```
