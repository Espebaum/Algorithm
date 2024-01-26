import sys
input = sys.stdin.readline
l = lambda : list(map(int,input().split()))

N, Q = l()
a = l()
bias = 0

for _ in range(Q):
    c = l()
    if c[0] == 1:
        i, x = c[1], c[2]
        i -= 1
        a[(i + bias) % N] += x
    elif c[0] == 2:
        s = c[1]
        bias = (bias - s + N) % N
    else:
        s = c[1]
        bias = (bias + s) % N
    
for i in range(N):
    print(a[(i + bias) % N], end=' ')
