## Extended Euclidean Algorithm

While the euclidean algorithm calculates just the gcd of a & b, the extended version finds ways to represent gcd in terms of a & b's coefficients:

![](https://quicklatex.com/cache3/d2/ql_ff6e64da2e77b7e6eda0bf975169fad2_l3.png)

*****Algorithm**

```
integer gcd(integer a, integer b, integer &x, integer &y)
    if b is 0
        x = 1
        y = 0
        
        return a

    integer x1
    integer x2

    integer d = gcd(b, a % b, x1, y1)

    x = y1
    y = x1 - y1 * (a / b)

    return d
end

integer a
integer b
integer c
integer d

a = input()
b = input()
c = input()
d = input()

write(gcd(a, b, c, d))

```
