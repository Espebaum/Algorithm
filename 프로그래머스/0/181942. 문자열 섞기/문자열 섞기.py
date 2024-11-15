def solution(str1, str2):
    lst = [""] * (len(str1) + len(str2))
    for i in range(len(str1)):
        lst[i * 2] = str1[i]
    for i in range(len(str2)):
        lst[1 + i * 2] = str2[i]
    return ''.join(lst)