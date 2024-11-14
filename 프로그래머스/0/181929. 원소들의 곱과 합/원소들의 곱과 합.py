from math import prod

def solution(num_list):
    ss = sum(num_list)**2
    p = prod(num_list)
    if p < ss: return 1
    return 0