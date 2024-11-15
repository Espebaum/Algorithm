def solution(a, d, included):
    l = len(included)
    arr = [a + d * i for i in range(l)]
    return sum([i if k == True else 0 for i, k in zip(arr, included)])