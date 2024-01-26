import sys
input = sys.stdin.readline

N = int(input())
a = []
for i in range(N):
    a.append(list(map(int, input().split())))
a.sort()
for x, y in a:
    print(x, y)