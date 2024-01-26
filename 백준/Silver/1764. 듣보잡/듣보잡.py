import sys
input = sys.stdin.readline

N, M = map(int, input().split())
s1, s2 = set(), set()
for i in range(N):
    s1.add(input().strip())

for i in range(M):
    s2.add(input().strip())
    
print(len(s1 & s2))

s3 = sorted(s1 & s2)
for x in s3:
    print(x)
