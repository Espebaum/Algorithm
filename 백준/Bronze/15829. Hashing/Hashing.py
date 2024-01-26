N = int(input())
A = [chr(i) for i in range(97, 123)]
M = 1234567891
D = dict()
for i in A:
    D[i] = ord(i) - 96

I = input()
S = list(I)

SH = []
mul = 0
for i in S:
    SH.append(D[i] * (31**mul))
    mul += 1
print(sum(SH)%M)