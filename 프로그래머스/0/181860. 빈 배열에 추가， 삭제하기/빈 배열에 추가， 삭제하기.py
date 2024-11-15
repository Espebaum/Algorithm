def solution(arr, flag):
    lst = []
    for n, b in zip(arr, flag):
        if b == True:
            for i in range(n*2):
                lst.append(n)
        else:
            for i in range(n):
                lst.pop()
                
    return lst