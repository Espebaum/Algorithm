import sys
input = sys.stdin.readline

N = int(input())
M = int(input())

adj = [[] for i in range(N+1)]
for i in range(M):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

visited = [0] * (N+1)
ans = 0 
def dfs(now):
    global ans
    for child in adj[now]:
        if visited[child]:
            continue
        ans += 1
        visited[child] = 1
        dfs(child)
visited[1] = 1
dfs(1)
print(ans)