def solution(my_string, is_suffix):
    for i in range(0, len(my_string)):
        suffix = ''.join(k for m, k in enumerate(my_string) if m >=i)
        print(suffix)
        if is_suffix == suffix: return 1
    return 0