def solution(myString, pat):

    sw = lambda s: ''.join('B' if c == 'A' else 'A' if c == 'B' else c for c in s)
    myString = sw(myString)
    idx = myString.find(pat)
    # print(myString)
    # print(idx)
    
    if idx != -1: return 1
    else: return 0
    
    return 1557