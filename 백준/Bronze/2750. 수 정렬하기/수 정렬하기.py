N = int(input())
A = []
for i in range(N):
    A.append(int(input()))

for i in range(N):
    minval = 9999
    index = -1
    for j in range(i, N):
        if minval > A[j]:
            minval = A[j]
            index = j
    A[i], A[index] = A[index], A[i]
for i in range(N):
    print(A[i], end = ' ')