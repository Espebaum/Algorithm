def solution(num_str):
    print([int(i) for i in num_str])
    return sum([int(i) for i in num_str]) # list comprehension