import sys
input = sys.stdin.readline
from collections import deque

N, K = map(int, input().split())
J = deque([i for i in range(1, N+1)])

ans = []
while J:
    for _ in range(K):
        J.append(J[0])
        J.popleft()
    ans.append(J[-1])
    J.pop()

print('<'+ans.__str__().strip('[]')+'>')
