def solution(num_list):
    if len(num_list) >= 11:
        return sum(num_list)
    else:
        product = 1
        for i in num_list:
            product *= i
    return product