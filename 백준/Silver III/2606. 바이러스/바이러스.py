import sys
n = int(sys.stdin.readline()) # number of computers
p = int(sys.stdin.readline()) # number of pairs connecting each other

graph = [[] for _ in range(n+1)]
for i in range(p):
    a,b = map(int,sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

virus = [] # visited list
queue = []
virus.append(1)
queue.append(1)

while True:
    parent = queue.pop(0)
    for i in graph[parent]:
        if i not in virus:
            virus.append(i)
            queue.append(i)
    if len(queue) == 0:
        break

print(len(virus)-1)