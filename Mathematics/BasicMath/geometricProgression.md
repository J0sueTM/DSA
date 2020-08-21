# Geometric Progression

A sequence of numbers is called a "Geometric Progression" if the ratio of any two consecutive terms is always same

* * *

### Every G.P. must have

- **Initial term** is the first number of the sequence
- **Common ratio** is the ratio between any two consecutive terms in the sequence
    * Positive, then the terms' sign will be the same forever
        * **Greater than 1**, then the terms will keep the sign growing towards positive infinity
    * Negative, then the terms' sign will alternate
        * **-1**, then the terms will be the same, but the sign will alternate
        * **< -1**, then the terms will grow towards infinity alternating
    * **> -1 && < 1**, then the terms will decay towards zero

**Example**

$$110 --> 220 --> 440 --> 880 --> 1760.$$

```
initial term = 110
ration = 2
positive
```

### Formulas

**N<sup>th</sup> term of an G.P.**

```
a = sequence
r = common ratio
n = position of nth term
```

$$a_{n} = a_{1}\times r^{n - 1}.$$

**Sum of first N<sup>th</sup> terms of an G.P.**

```
S = sum
r = common ratio
a = sequence
n = range of sum
```

$$S_{n} = \frac{a\times(r^{n} - 1)}{r - 1}
