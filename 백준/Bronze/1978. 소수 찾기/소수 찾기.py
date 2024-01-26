import sys
input = sys.stdin.readline

N = int(input())
sosu = list(map(int, input().split()))

sum = 0
for i in sosu:
    if i > 1:
        for j in range(2, i):
            if i%j == 0:
                break
        else:
            sum += 1
print(sum)
