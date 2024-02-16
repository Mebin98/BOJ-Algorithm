from collections import deque
import sys
n,m = map(int,sys.stdin.readline().split())

graph = [[] for _ in range(n+1)]
for i in range(m):
    a,b = map(int,sys.stdin.readline().split())
    graph[b].append(a)

def bfs(start):
    infected = [False]*(n+1)
    infected[start] = True
    queue = deque([start])
    cnt = 0
    while queue:
        parent = queue.popleft()
        for i in graph[parent]:
            if not infected[i]:
                queue.append(i)
                infected[i] = True
                cnt += 1
    return cnt

result = []
for i in range(n):
    result.append(bfs(i+1))
max_val = max(result)
for i in range(n):
    if result[i] == max_val:
        print(i+1,end=" ")