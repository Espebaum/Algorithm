def solution(num_list, n):
    a = [k for i, k in enumerate(num_list) if i < n]
    b = [k for i, k in enumerate(num_list) if i >= n]
    return b+a