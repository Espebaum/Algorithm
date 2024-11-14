def solution(num_list):
    for i, k in enumerate(num_list):
        if k < 0: return i
    return -1