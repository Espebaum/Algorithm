def solution(arr):
    l = len(arr)
    c = 0
    
    for s in range(1, 11):
        if 2**(s-1) < l <= 2**s:
            c = 2**s
    
    for i in range(c - l):
        arr.append(0)
    
    return arr