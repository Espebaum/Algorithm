def solve():
    k = int(input())
    n = int(input())
    print(a[k][n])

a = [[0]*20 for i in range(20)]

for i in range(1,16):
    a[0][i]=i
for i in range(1, 16):
    for j in range(1, 16):
        a[i][j] = a[i-1][j] + a[i][j-1]

tc = int(input())
for _ in range(tc):
    solve()