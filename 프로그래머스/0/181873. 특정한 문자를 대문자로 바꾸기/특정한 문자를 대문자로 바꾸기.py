def solution(my_string, alp):
    u = lambda x: ''.join(c.upper() if c == alp else c for c in x)
    answer = u(my_string)
    return answer