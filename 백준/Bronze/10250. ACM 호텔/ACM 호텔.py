def solve():
    H, W, N = map(int, input().split())
    q, r = N // H, N % H
    if r == 0:
        r = H
        q -= 1
    print(100*r + q+1)
    return

tc = int(input())
for _ in range(tc):
    solve()