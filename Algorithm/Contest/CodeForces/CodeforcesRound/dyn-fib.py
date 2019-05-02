def dyn_fib(n):
    prev = 1
    prevrev = 1
    if n <= 1:
        return 1
    else:
        for i in range(2, n+1):
            temp = prev + prevrev
            prevprev = prev
            prev = temp
    return prev


print(dyn_fib(int(input())))


