def solution(strArr):
    f = lambda c, i: c.lower() if i % 2 == 0 else c.upper()
    return [f(c, i) for i, c in enumerate(strArr)]