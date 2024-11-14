def solution(n):
    lst = []
    lst.append(n)
    while (1):
        if n == 1:
            break
        elif n % 2 == 1:
            n *= 3
            n += 1
            lst.append(n)
        else:
            n /= 2
            lst.append(n)
    return lst