import sys
input = sys.stdin.readline

N = int(input())
T = []
for i in range(N):
    T.append(list(map(int, input().split())))
T.sort(key = lambda x : (x[1], x[0]))

cnt = 1
end_time = T[0][1]
for i in range(1, N):
    if T[i][0] >= end_time:
        cnt += 1
        end_time = T[i][1]

print(cnt)
