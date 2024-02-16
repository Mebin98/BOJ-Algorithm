import sys
sys.setrecursionlimit(10**6)
n,m = map(int,sys.stdin.readline().split())
graph = [[] for _ in range(n+1)]
for i in range(m):
    u,v = map(int,sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)
visited = []

def dfs(graph,i,visited):
    for g in graph[i]:
        if g not in visited:
            visited.append(g)
            dfs(graph,g,visited)           
cnt = 0
for i in range(1,n+1):
    if i not in visited:
        visited.append(i)
        dfs(graph,i,visited)
        cnt += 1
print(cnt)