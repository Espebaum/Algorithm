def solution(num_list):
    return int(''.join([str(num) for num in num_list if num % 2 == 0]))+int(''.join([str(num) for num in num_list if num % 2 == 1]))