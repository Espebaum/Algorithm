def solution(a, b):
    sa = str(a)
    sb = str(b)
    if int(sa + sb) > int(sb + sa):
        return int(sa+sb)
    return int(sb+sa)