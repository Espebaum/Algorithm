import sys
input = sys.stdin.readline

N = int(input())
O = []
for _ in range(N):
    O.append(input().split())
O.sort(key = lambda x : int(x[0]))
for i in range(N):
    print(O[i][0], O[i][1])