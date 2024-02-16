import sys
n,m = map(int,sys.stdin.readline().split())

graph = [[] for _ in range(n+1)]
for i in range(m):
    a,b = map(int,sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [False]*(n+1)
visited[1] = True
queue = []
queue.append(1)
depth = []
depth.append(0)
depth_list = []
depth_list.append([1,0]) #(index,depth)

while queue:
    parent = queue.pop(0)
    d = depth.pop(0)
    for i in graph[parent]:
        if visited[i] == False:
            visited[i] = True
            queue.append(i)
            depth.append(d+1)
            depth_list.append([i,d+1])

depth_list = [x for x in depth_list if x[1] == d]
d_list = sorted(depth_list)
print(d_list[0][0],d,len(depth_list))   