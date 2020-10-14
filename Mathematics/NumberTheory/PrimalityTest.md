# Primality Test

The primality test is as following: Given a positive integer, test whether that number is prime or not. 

Remember: A prime is a natural number greater than 1 that has no positive divisors other than 1 and itself.

**There are more than one method for the primality test**, but we'll be covering just the following:

- Brute force method

[If you want to see other methods](https://en.wikipedia.org/wiki/Primality_test))

### Brute Force Method

```
function isPrime(integer number):
    if number is less or equal than 1:
        return false
    if number is less or equal than 3:
        return true

    if number % 2 is 0 or number % 3 is 0:
        return false

    for integer i = 5; i * i <= number; i += 6:
        if n % i is 0 or n % i + 2 is 0:
            return false

    return true
endfunction

isPrime(input())
```

**Explanation**

The brute force method, as it's name says, uses iteration to compare numbers until the desired number, if all of them can't divide the passed number, then it's a prime

1 - **Verify if the number is less or equal to 1** There are not negative prime numbers, also 0 and 1 are not prime
    * Return false
2 - **Verify if the number is less or equal to 3** We already checked 0 and 1, so this condition checks if the number is whether 2 or 3. Both 2 and 3 are prime
    * Return true
3 - **Verify if the remainder of the number by 2 is 0 or the remainder of the number by 3 is 0** By checking if the number is a multiple of 2, we remove all the even numbers. By checking  less or equal to 3** We already checked 0 and 1, so this condition checks if the number is whether 2 or 3. Both 2 and 3 are prime
    * Return true
4 - **Verify if the remainder of the number by 2 is 0 or the remainder of the number by 3 is 0** By checking if the number is a multiple of 2, we remove all the even numbers. By checking if the number is a multiple of 3, we remove all the numbers that precede primes (primes also can be expressed as 6 * k + i)

5 - **Iterate from 5 to power of number by adding 6)**
    * **Check if the number % i is 0 or n % i + 2 is 0**

6 - Finally, if we got untill here, so there's no divisors for number
