import sys
n,m = map(int,sys.stdin.readline().split())

heavier =[[] for _ in range(n)] # 정방향
lighter =[[] for _ in range(n)] # 역방향
for i in range(m):
    a,b = map(int,sys.stdin.readline().split())
    heavier[a-1].append(b-1)
    lighter[b-1].append(a-1)
# input : n = 1~5
# graph : n = 0~4
def bfs(heavier,lighter,start,n):
    heavy = []
    light = []
    visited = [False]*n
    queue = []
    visited[start] = True
    queue.append(start)

    while True: # heavier mode / add lighter
        parent = queue.pop(0)
        for i in heavier[parent]:
            if visited[i] == False:
                visited[i] = True
                queue.append(i)
                light.append(i)
                if len(light) > (n-1)/2:
                    return False
        if len(queue) == 0:
            visited = [False]*n
            visited[start] = True
            queue.append(start)
            break
    while True: # lighter mode / add heavier
        parent = queue.pop(0)
        for i in lighter[parent]:
            if visited[i] == False:
                visited[i] = True
                queue.append(i)
                heavy.append(i)
                if len(heavy) > (n-1)/2:
                    return False
        if len(queue) == 0:
            break

    return True

bead = 0
for i in range(n):
    if not bfs(heavier,lighter,i,n):
        bead += 1

print(bead)