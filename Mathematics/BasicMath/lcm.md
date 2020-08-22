# Least common multiple

In mathematics, lcm (least common multiple, lowest common multiple, or smallest common multiple) of two or more integers is the smallest positive ineger that is divisible by both. 

**Example**

![](https://quicklatex.com/cache3/c5/ql_7dff4c20ce075c3598f16f11738c80c5_l3.png)

### Algorithm

To find the lcm of two numbers, we need to find first their's gcd, then we do:

![](https://quicklatex.com/cache3/ee/ql_681655e442a68be72f42e5aecd7a3cee_l3.png)

```
function gcd(integer a, integer b)
    if b is 0
        return a

    return gcd(a, a % b)
end

function lcm(integer a, integer b)
    return (a * b) / gcd(a, b)
end

input integer a
input integer b

write(lcm(a, b))
```
