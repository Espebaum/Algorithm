def solution(before, after):
    a = [0] * 128
    b = [0] * 128
    for c in before:
        a[ord(c)] += 1
    for c in after:
        b[ord(c)] += 1
    return 1 if a == b else 0
    