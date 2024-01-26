def solve():
    PS = input()
    PS_list = list(PS)
    sum = 0
    for _ in PS_list:
        if _ == '(':
            sum += 1
        else: sum -= 1
        if sum < 0:
            print("NO")
            break
    if sum > 0:
        print("NO")
    elif sum == 0:
        print("YES")
    return

tc = int(input())
for _ in range(tc):
    solve()