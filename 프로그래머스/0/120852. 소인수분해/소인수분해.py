def solution(n):
    f = []
    div = 2
    while n > 1:
        while n % div == 0:
            f.append(div)
            n //= div
        div += 1
        if div * div > n:
            if n > 1:
                f.append(n)
                break
    return sorted(list(set(f)))
            
    