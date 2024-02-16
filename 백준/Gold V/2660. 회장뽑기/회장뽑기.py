import sys
n = int(sys.stdin.readline()) 
graph = [[] for _ in range(n+1)]
while True:
    a,b = map(int,sys.stdin.readline().split())
    if a == -1 and b == -1:
        break
    graph[a].append(b)
    graph[b].append(a)

def chairman(graph,start):
    visited = []
    queue = []
    depth = []
    s = start
    visited.append(s)
    queue.append(s)
    depth.append(0)

    while True: 
        parent = queue.pop(0)
        d = depth.pop(0)
        for i in graph[parent]:
            if i not in visited:
                visited.append(i)
                queue.append(i)
                depth.append(d+1)
        if len(queue) == 0:
            break
    return d

result = []
for i in range(n):
    score = chairman(graph,i+1)
    result.append(score)

cnt = len([x for x in result if x == min(result)])
who = [i+1 for i,x in enumerate(result) if x == min(result)]
print(min(result),cnt)
print(' '.join(map(str,who)))