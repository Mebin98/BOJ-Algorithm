import sys
n,m = map(int,sys.stdin.readline().split())
graph = [[] for _ in range(n+1)]

for i in range(m):
    a,b = map(int,sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

def kevin(graph,start):
    visited = []
    depth = []
    queue = []
    score = []
    s = start

    visited.append(s)
    depth.append(0)
    queue.append(s)

    while True:
        parent = queue.pop(0)
        d = depth.pop(0)

        for i in graph[parent]:
            if i not in visited:
                visited.append(i)
                depth.append(d+1)
                score.append(d+1)
                queue.append(i)
        
        if len(queue) == 0:
            break

    return score

min = float('inf')
who = 0
for i in range(n):
    score = kevin(graph,i+1)
    if sum(score) < min:
        min = sum(score)
        who = i+1

print(who)