def solution(myString, pat):
    st = 0
    while True:
        idx = myString.find(pat, st)
        if idx == -1:
            break
        st += 1
    str = myString[0:st-1]
    return str+pat
        