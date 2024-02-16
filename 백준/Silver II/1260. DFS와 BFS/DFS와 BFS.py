import sys
n,m,v = map(int,sys.stdin.readline().split()) # start at v
graph = [[] for _ in range(n+1)] # 0,1,2,....,N
for i in range(m):
    a,b = map(int,sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

graph = [sorted(g,reverse=True) for g in graph]
def dfs(graph,v):
    visited,stack,dfs_list = [],[],[]
    stack.append(v)
    visited.append(v)
    while True:
        parent = stack.pop(len(stack)-1)
        dfs_list.append(parent)
        for i in graph[parent]:
            if i not in visited:
                stack.append(i)
                visited.append(i)
            elif i in stack:
                stack.remove(i)
                stack.append(i)
        if len(stack) == 0:
            break
    dfs_list = [str(x) for x in dfs_list]
    return ' '.join(dfs_list)
print(dfs(graph,v))

graph = [sorted(g) for g in graph]
def bfs(graph,v):
    visited,queue,bfs_list = [],[],[]
    queue.append(v)
    visited.append(v)
    while True:
        parent = queue.pop(0)
        bfs_list.append(parent)
        for i in graph[parent]:
            if i not in visited:
                queue.append(i)
                visited.append(i)
        if len(queue) == 0:
            break
    bfs_list = [str(x) for x in bfs_list]
    return ' '.join(bfs_list)
print(bfs(graph,v))