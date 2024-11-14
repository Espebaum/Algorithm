def solution(myString):
    f = lambda x: ''.join(c.upper() if c == 'a' else c.lower() if c != 'a' else c for c in x)
    str = f(myString)
    f = lambda x: ''.join(c.upper() if c == 'a' else c for c in x)
    return f(str)