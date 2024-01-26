import sys
input = sys.stdin.readline

N, M = map(int, input().split())
P = dict()
P2 = dict()
for i in range(N):
    S = input().rstrip()
    P[S] = i+1
    P2[i+1] = S

for i in range(M):
    I = input().rstrip()
    if '0' <= I[0] <= '9':
        print(P2[int(I)])
    else: 
        print(P[I])