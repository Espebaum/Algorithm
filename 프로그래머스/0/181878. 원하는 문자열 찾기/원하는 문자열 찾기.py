def solution(myString, pat):
    n = ''.join([c.lower() if 'A' <= c <= 'Z' else c for c in myString])
    pat = ''.join([c.lower() if 'A' <= c <= 'Z' else c for c in pat])
    if n.find(pat) != -1: return 1
    return 0