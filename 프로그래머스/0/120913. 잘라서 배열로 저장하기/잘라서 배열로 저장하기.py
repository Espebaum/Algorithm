def solution(my_str, n):
    s = ""
    lst = []
    for i, c in enumerate(my_str):
        s += c
        if (i + 1) % n == 0 or (i + 1) == len(my_str):
            lst.append(s)
            s = ""
    return lst