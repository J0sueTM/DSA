def isPrime(n):
    if n <= 1:
        return False
    if n <= 2:
        return True

    if n % 2 == 0 or n % 3 == 0:
        return False

    counter = 5
    while (counter * counter <= n):
        if n % counter == 0 or n % counter + 2:
            return False

        counter += 6

    return True

n = int(input())

if (isPrime(n)):
    print("Yes")
else:
    print("No")
