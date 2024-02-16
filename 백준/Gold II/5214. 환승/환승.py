import sys
n,k,m = map(int,sys.stdin.readline().split())
# 1,2,...,n [station]
# n+1,n+2,...,n+m [hypertube]
graph = [[] for _ in range(n+m+1)]
for i in range(m):
    hp = sys.stdin.readline().split()
    temp = list(map(int,hp))
    graph[n+1+i].extend(temp)
    for j in temp:
        graph[j].append(n+1+i)

# 갈 수 없다면, -1을 출력
visited = [False]*(n+m+1)
depth = []
queue = []

visited[1] = True
depth.append(1)
queue.append(1)

# 역 != hypertube
can = False
while can == False:
    parent = queue.pop(0)
    d = depth.pop(0)
    if parent == n:
        answer = d
        can = True
    for i in graph[parent]:
        if not visited[i]:
            visited[i] = True
            if 1<=i<=n:
                depth.append(d+1)
            else:
                depth.append(d)
            queue.append(i)
    if len(queue) == 0:
        break

if can == False:
    print(-1)
else:
    print(answer)