def solution(intStrs, k, s, l):
    lst = []
    for m in intStrs:
        if int(m[s:s+l]) > k: 
            lst.append(int(m[s:s+l]))
    return lst