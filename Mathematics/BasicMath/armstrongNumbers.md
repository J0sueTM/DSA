# Armstrong Numbers

In mathematics, armstrong number is a number that the sum of the power of it's digits by the number of digits is itself

```
abcd = pow(a, 4) + pow(b, 4) + pow(c, 4) + pow(d, 4)

abcd = a * a * a * a +
       b * b * b * b +
       c * c * c * c +
       d * d * d * d
```

**Example**

![](https://quicklatex.com/cache3/8e/ql_b1f10d1776469b3163baea329a6d158e_l3.png)

**Algorithm**

```
function size(integer n)
    integer x = 0
    while n not 0 do
        ++x
        n /= 10
    end

    return x
end

function isAr(integer n)
    integer s = size(n)
    integer t = s
    integer c = 0

    while t not 0 do
        integer r = t % 10
        c += power(r, n)
        t /= 10
    end

    return (c is s)
end


integer number
number = input()

write(isAr(number))
```
