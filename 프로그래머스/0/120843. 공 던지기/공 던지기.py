def solution(numbers, k):
    a = 0
    for i in range(k):
        a = i * 2
    s = a % len(numbers)
    return numbers[s]