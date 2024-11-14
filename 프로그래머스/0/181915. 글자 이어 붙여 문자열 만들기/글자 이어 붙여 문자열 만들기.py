def solution(my_string, index_list):
    return ''.join(my_string[int(idx)] for idx in index_list)