def solution(n, k):
    return [k*i for i in range(1, int(n / k) + 1)]