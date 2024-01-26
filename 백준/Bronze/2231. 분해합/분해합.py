import sys
input = sys.stdin.readline

N = int(input())
R = 0
num = []
for i in range(N):
    isum = sum(list(map(int,str(i))))
    if i+isum == N:
        R = i
        break
print(R)
