def solution(bin1, bin2):
    d1 = int(bin1, 2)
    d2 = int(bin2, 2)
    ans = d1+d2
    return bin(ans)[2:]