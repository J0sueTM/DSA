# Dynamic Programming

Dynamic programming is an optimization method that breaks a problem into smaller steps and store then, so we can use it later, saving time and processing.

**Recognize**

There are times that a greedy algorithm does not solve the problem, but a Dynamic programming approache does. So, dynamic programming should be used in the following circumstances:
    - Overlapping subproblem: When a problem requires re-computation. Promblems where data has already appeared not just once.
    - Optimal subproblems: When a problem requires re-computation of it's own pieces. So, we can use a sub-problem to solve another one inside a bigger one.

We also can identify a problem that can be solved with dynamic programming if it asks the following:
    - **Combinatorics** How many? How much?
        - How many ways to make a change?
        - How many moves to get from point A to point B?
        - How many ways to sum subsets?
    - **Optimization** Minimum? Maximum? At least?
        - What's the maximum ways to change?
        - What's the minimum moves to get from point A to point B?
        - Wha't the largest summed subset?


Solution process:
    - Define objective function
    - Identify base case
    - Recurrence relation
    - Order of computation
    - Location of the answer

**Example**

Let's take as example, a function that finds a certain number in a defined position of the fibonacci number. Eg. fib(5) = 5.

**Objective function**: Fib(i) is the i-th fibonacci number
**Base case**: the first two numbers, 1 and 1
**Recurrence relation**: Fib(i) = Fib(i - 1) + Fib(i - 2)
**Order of computation**: Bottom up (we'll also use recursion for learning purposes)
**Location fo the answer**: The given position - 1 (- 1 since array works from 0 to n - 1)

It's simple for a human being to approach this solution, just sum the previous fibonacci number with the actual number. However, it doesn't work the same way for the computer; it doesn't know that the previous number is 4. So, the real solution comes by iterating though all the way back, until the first fibonacci number: 1, as following.

```
function fib(integer number):
    if number is 1 or number is 2:
        return 1
    endif

    return fib(n - 1) + fib(n - 2)
endfunction
```

This solution works, but it repeats the same computation a couple times. It doesn't really matter in this case, but think about a relatively larger number. Then, there's perceptive computation time loss.

Using dynamic programming, we use memoization, which is not the same as memorization. Memoization is basically "storing" the values, so we don't need to computated them again, but use them instead. Here goes the same function but with dynymaic programming applied.

```
integer[] memoization_array;

function fib(integer number):
    if memoization_array[number] is not NULL:
        return memoization_array[n]
    endif

    memoization[n] = fib(number - 1) + fib(number - 2)
    return memoization[n]
endfunction

```

In this case, we're recursing from the target position until the bottom. There's other approach, wich is called bottom-up In this approach, we start at the bottom, and iterate all the way up until we rearch the target position. Here's the same function with the bottom-up approach.

```
function bottom-up(integer number):
    if number is 1 or number is 2:
        return 1
    endif

    integer[number + 1] bottom-up_array
    bottom-up_array[0] = 1
    bottom-up_array[1] = 1

    for i in range(3, number):
        bottom-up_array[i] = bottom-up_array[i - 1] + bottom-up_array[i - 2]

    return bottom-up_array[n]
endfunction
```
