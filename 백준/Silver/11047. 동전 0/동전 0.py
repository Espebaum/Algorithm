N, K = map(int, input().split())
A = []

for i in range(N):
    A.append(int(input()))
A.reverse()

ans = 0
for i in range(N):
    ans += K // A[i]
    K %= A[i]
print(ans)
