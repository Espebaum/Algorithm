import sys
input = sys.stdin.readline

N = int(input())
cnt = [0] * 10001
for i in range(N):
    num = int(input())
    cnt[num] += 1

for i in range(10001):
    if cnt[i] != 0:
        for j in range(cnt[i]):
            print(i)