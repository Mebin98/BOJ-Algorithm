import sys
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
graph = [[] for _ in range(n+1)]
for i in range(m):
    a,b = map(int,sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

visited = []
queue = []
depth = [] # depth queue
answer = []

if len(graph[1]) != 0:
    visited.append(1)
    queue.append(1)
    depth.append(0)
    answer.append(0)

while len(graph[1]) != 0:
    p = queue.pop(0)
    p_depth = depth.pop(0)

    for i in graph[p]:
        if i not in visited:
            visited.append(i)
            queue.append(i)
            depth.append(p_depth+1)
            answer.append(p_depth+1)

    if len(queue) == 0:
        break

if len(graph[1]) == 0:
    print(0)
else:
    print(len([x for x in answer if x==1 or x==2]))